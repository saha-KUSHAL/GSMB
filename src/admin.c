#include "system.h"

void admin()
{
    if (login() == pass)
    {
        printf("\n");
        red();
        c_printf("--ADMIN PANEL--");
        green();
        printf("\n--------------\t\t\t----------------");
        printf("\n|(1)View Data|\t\t\t|(2)Manage Data|");
        printf("\n--------------\t\t\t----------------");
        printf("\n--------------\t\t\t---------");
        printf("\n|(3))Settings|\t\t\t|(0)Exit|");
        printf("\n--------------\t\t\t---------");
        reset();
    }
    else
        printf("\nFail");
}