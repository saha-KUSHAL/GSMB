#include "system.h"

void c_printf(char s[])
{   
    int width = 80;
    int pad = (strlen(s) >= width) ? 0 : (width - strlen(s)) / 2;
    printf("%*.*s%s\n", pad, pad, " ", s);
}