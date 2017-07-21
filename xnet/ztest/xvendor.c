#include "format.h"
#include "xvendor.h"

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage : %s mac(11:22:33:44:55:66)\n", argv[0]);
    return 1;
  }
  create_oui_table();

  char *mac = string_etheraddr((unsigned char *)argv[1]);

  printf("\nMac Vendor = [%s]\n", get_oui_info((unsigned char *)mac));

  destroy_oui_table();
  return 0;

}
