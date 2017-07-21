#include <stdio.h>

#include "format.h"
#include "xstring.h"
#include "xrbt.h"
#include "xarp.h"
#include "xvhost.h"

static XRBTR32 *vhost_table = NULL;

static void xvhost_save_info (void)
{
  FILE *fp;
  XVHOST *vh;
  char ip[IPV4_STR_SIZE];

  if ((fp = fopen(XFIRE_ARP_INFO_FILE, "w+"))) {

    fprintf(fp, "ipaddr portid\n");
    if ((vh = (XVHOST *)xrbt32_first(vhost_table))) do {
      fprintf(fp, "%s %d\n", intoab(vh->my_ip, ip),  vh->portid);
    } while ((vh = (XVHOST *)xrbt32_next((XRBTN32 *)vh)));

    fclose(fp);
  }
}

static void xvhost_load_info (void)
{
  FILE *fp;
  xdevice *xdev;
  XARP_VIRTUAL *virtual;

  if ((fp = fopen(XFIRE_VHOST_CFG_FILE, "r"))) {
    char buf[1024], *bptr[2];
    XVHOST *vh;
    int portid, new;
    ub32 ip;

    while (fgets(buf, sizeof(buf), fp)) {
      
      if (buf[0] == '#'|| buf[0] == '\n') continue;
      if (msplit(buf, bptr, 2, " \t") == 2) {
        ip =  atoin(bptr[0]);
        portid = atoi(bptr[1]);
        xdev = xpacket_get_xdevice(portid);
        if (xdev == NULL) {
          printf("xvhost_load_info device not found : portid =  %d\n", portid);
          continue; 
        }
        vh = (XVHOST *)xrbt32_insert(vhost_table, ip, &new);
        if (new) {
          vh->my_ip = ip;
          vh->portid = portid;
          virtual = xarp_add_virtual_mac(ip, portid, XGW_DEV_TYPE);
          if (virtual) xarp_add_dev_ip(virtual->ip, virtual->xdev->xmac, virtual->xdev->portid, XGW_DEV_TYPE);
        }
      }
    }
    fclose(fp);
  } else {
    xvhost_save_info();
  } 
}


void xvhost_create (void)
{
  vhost_table   = xrbt32_create(sizeof(XVHOST), 0);
  xvhost_load_info();
}

void xvhost_destroy (void)
{
  xrbt32_destroy(vhost_table);
} 



void xvhost_add (xpacket *xp, ub32 ipaddr, ub32 netmask, ub32 router, ub32 dns_ip, ub32 lease_time)
{
   XVHOST *vh;

   vh = (XVHOST *)xrbt32_insert(vhost_table, ipaddr, NULL);
   vh->my_ip = ipaddr;
   vh->portid = xp->xdev->portid;

   vh->netmask = netmask;
   vh->router  = router;
   vh->dns_ip  = dns_ip;
   vh->lease_time = lease_time;

   xarp_add_virtual_mac(ipaddr, vh->portid, XGW_DEV_TYPE);
}

void xvhost_del (ub32 ipaddr)
{
  xrbt32_delete(vhost_table, ipaddr);
}

int xvhost_find (ub32 ipaddr)
{
  if (xrbt32_search(vhost_table, ipaddr)) return 1;
  return 0;
}



