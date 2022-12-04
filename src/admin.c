#include "system.h"

void admin()
{
    enum state status;
    status = login();
    if (status == pass)

        printf("\nPass");
    else
        printf("\nFail");
}