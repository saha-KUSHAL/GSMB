#include "src/system.h"
int main()
{
    c_printf("Gitaram Student Management BUS\n");
    while(1)
    
    {
        int ch;
        printf("\tEnter 0 to exit.");
        scanf("%d",&ch);
        switch (ch){
            case 0: exit(0);
            break;
            default: c_printf("\n\tEnter any inputs between 0 to ");
        }
        
    }
    return (0);
}