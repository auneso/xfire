#include <time.h>
#include <string.h>
#include <ctype.h>

#include "xprintf.h"
#include "thread.h"
#include "xconfig.h"
#include "xfire.h"
#include "mongoose.h"
#include "json.h"
#include "jsonrpc.h"

extern void jsonrpc_registry_method();


static int xjsonrpc_process_call (struct mg_connection *conn, size_t content_len)
{
  const char *fmt = "%a, %d %b %Y %H:%M:%S %Z";
  time_t ct = time(NULL);
  char date[64], *rsp, *req = malloc(content_len + 1);
  size_t len;
  

  len = mg_read(conn, req, content_len);
  if (len <= 0 || len != content_len) {
    send_http_error(conn, 411, "Invalid Content-Length", "JSON_RPC Content Length: %d", len);
    free(req);
    return 1;
  }
  req[len] = 0;


#if 0
 printf("REQ len = %ld, data = [%s]\n", len, req);
#endif

  /* Process the JSON-RPC. */
  rsp = jsonrpc_process(req);
  if (rsp) {
    len = strlen(rsp);
    (void) strftime(date, sizeof(date), fmt, gmtime(&ct));

    (void) mg_printf(conn,
          "HTTP/1.1 200 OK\r\n"
          "Date: %s\r\n"
          "Content-Type: application/json-rpc\r\n"
          "Content-Length: %ld\r\n"
          "Connection: %s\r\n\r\n",
           date, len, suggest_connection_header(conn));
    mg_write(conn, rsp, len);

#if 0
    printf("RSP len = %ld, data = [%s]\n", len, rsp);
#endif

    free(rsp);
  } else {
    send_http_error(conn, 500, "Internal Server Error", "JSON_RPC");
  }
  free(req);
  return 1;
}

static int rpc_process_call (struct mg_connection *conn)
{
  const struct mg_request_info *ri = mg_get_request_info(conn);
  size_t content_len = mg_get_content_len(conn);

  if (memcmp(ri->request_method, "POST", 4) == 0 && content_len > 0) {
    if (memcmp(ri->uri, "/JSON-RPC", 9) == 0) {
      return xjsonrpc_process_call(conn, content_len);
    }
  }
  return 0;
}


static struct mg_context *xhttpd;

static void xhttpd_create (const char **options)
{
  struct mg_callbacks callbacks;

  jsonrpc_registry_method();

  memset(&callbacks, 0, sizeof(callbacks));
  callbacks.begin_request = rpc_process_call;
  if ((xhttpd = mg_start(&callbacks, NULL, options)) == NULL) {
    printf("\nAlready Running XDoS Web server\n");
    exit(1);
  }
}

void xhttpd_destroy (void)
{
  mg_stop (xhttpd);
}

static ub8 xcore = 0;
static ub16 xport = 8888;
static ub16 xthreads = 10;

void xhttpd_set_core (ub8 core)
{  xcore = core; }

void xhttpd_set_port (ub16 port)
{  xport = port; }

void xhttpd_set_threads (ub16 threads)
{ xthreads = threads; }


static void *run_manager (void *arg)
{
  ThreadAddTable((char *)arg, xcore, XFIRE_PRIORITY);

  char *options[7];
  char m_port[8], m_threads[8];

  xsprintf(m_port, "%d", xport);
  xsprintf(m_threads, "%d", xthreads);

  /* port, thread num */
  options[0] = "document_root";
  options[1] = XFIRE_HTTP_PATH;

  options[2] = "listening_ports";
  options[3] = m_port;

  options[4] = "num_threads";
  options[5] = m_threads;

  options[6] = NULL;

  xhttpd_create((const char **)options);
  return arg;
}


void xhttpd_thread (void)
{
  ThreadCreate(run_manager, (void *)"Httpd");
}
