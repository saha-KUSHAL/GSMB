#include "system.h"

void c_printf(char s[])
{
    int length=sizeof(s)-1,width=80;
    int pad = (length >= width) ? 0 : (width - length) / 2;
    printf("%*.*s%s\n", pad, pad, " ", s);
}