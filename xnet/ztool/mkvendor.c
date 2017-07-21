#include <stdio.h>
#include <string.h>

char *header = "/*\n"
               "** http://standards.ieee.org/develop/regauth/oui/oui.txt\n"
               "** Organizationally Unique Identifier (OUI) is a 24-bit number\n"
               "** 2011-12-07 HDS\n"
               "** 2012-04-12 HDS update\n"
               "** 2013-03-20 HDS update\n"
               "** 2016-02-02 HDS update\n"
               "*/\n"
               "struct _mac_vendor {\n"
               "  char *mac;\n"
               "  char *vendor;\n"
               "};\n"
               "static struct _mac_vendor mac_vendor[] = {\n";
int main ()
{
  FILE *in, *out; 
  char line[128], *vendor, *mac, *ptr, *q;

  if ((in = fopen("oui.txt", "r")) == NULL) {
    printf("Not Found mac-vendor.dat\n");
    return 1;
  }
  if ((out = fopen("xoui.h", "w+")) == NULL) {
    printf("Open Error xvendor.h\n");
    return 1;
  }
  
  fprintf(out, header);
  while (fgets(line, sizeof(line), in)) {
    if (*line == '#') continue;
    line[strlen(line)-1] = 0;
 
    if ((ptr = strstr(line, "(base 16)")) == 0) continue;
    vendor = ptr + strlen("(base 16)") + 1;
    while (*vendor <= ' ') vendor++;
    ptr = q = vendor;
    while (*ptr)
     if (*ptr == '"') ptr++;
     else *q++ = *ptr++;
   *q = 0;
    
    mac = line;
    while (*mac <= ' ') mac++;
    ptr = strchr(mac, ' ');
    *ptr = 0;
        
    fprintf(out, "{ \"%s\", \"%s\" },\n", mac, vendor);
  }  
  fprintf(out, "{ NULL, NULL }\n};\n");
  fclose(in); fclose(out);
} 
