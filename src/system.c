#include "system.h"

void c_printf(char s[])
{   
    int width = 80;
    int pad = (strlen(s) >= width) ? 0 : (width - strlen(s)) / 2;
    printf("%*.*s%s\n", pad, pad, " ", s);
}
bool mt_file(char s[])//checks if the file is empty or not
{
    FILE *fp;
    fp = fopen(s, "r");
    fseek(fp, 0, 2);
    if (ftell(fp) == 0)
        return true;
    else
        return false;
}