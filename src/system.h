#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum state{fail,pass}test;

void c_printf(char s[]);
void admin();
test login();//login function
bool mt_file(char s[]);//function to check a file is empty or not.



#endif