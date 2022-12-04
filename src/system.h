#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum state{fail,pass}test;
struct details
{
    long int password;
    char id[20];
}det;
void c_printf(char s[]);
void admin();
// void student();
enum state login();//login function
void login();
bool mt_file(char s[50]);



#endif