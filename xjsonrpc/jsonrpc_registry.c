#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "json.h"
#include "jsonrpc.h"
#include "xfire.h"

#include "json_traffic.h"
#include "json_alert_data.h"
#include "json_system.h"
#include "json_xarp_list.h"
#include "json_xdev_list.h"


void  jsonrpc_registry_method (void)
{
  jsonrpc_add_method("traffic.view.current",  Proc_View_Traffic);

#if 0
  jsonrpc_add_method("alert.view.list",       Proc_View_Alert_List);
  jsonrpc_add_method("alert.view.search",     Proc_View_Alert_List_Search);
#endif

  jsonrpc_add_method("system.info",           Proc_System_Info);

  jsonrpc_add_method("xarp.view.list",        Proc_View_XARP_List);

  jsonrpc_add_method("xdev.view.list",        Proc_View_Xdev_List);


}


