#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum state{fail,pass};
struct details
{
    long int password;
    char id[20];
} log;
void c_printf(char s[]);
void admin();


#endif