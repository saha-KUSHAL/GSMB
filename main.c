#include "src/system.h"
int main()
{
    int ch;
    system("COLOR 09");
    c_printf("Gitaram Student Management BUS\n");
    c_printf("------------------------------");
    red();
    printf("\nLogin as:");
    yellow();
    printf("\n----------\t\t\t------------\t\t\t---------");
    printf("\n|(1)admin|\t\t\t|(2)student|\t\t\t|(0)Exit|");
    printf("\n----------\t\t\t------------\t\t\t---------");
    reset();
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        admin();
        break;
    case 2:
       //student();
        break;
    case 3:
        exit(0);
        
    }
    scanf("%d", &ch); // holding the screen;
    return (0);
}