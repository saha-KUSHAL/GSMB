#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum state{fail,pass}test;
struct details
{
    long int password;
    char id[20];
}det;
void c_printf(char s[]);
void admin();
enum state login();//login function


#endif