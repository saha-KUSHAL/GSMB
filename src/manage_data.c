#include "system.h"
void manage_data() // manage data from ADMIN
{
    int ch = 4;
    cyan();
    c_printf("--MANAGE DATA--");

    blue();
    printf("\n--------\t\t\t-----------\t\t\t---------");
    printf("\n|(1)Add|\t\t\t|(2)Modify|\t\t\t|(0)Go Back|");
    printf("\n--------\t\t\t-----------\t\t\t---------");
    reset();
    printf("\n>");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1: create_data();
        break;
    case 2: // modify_data();
        break;
    case 0:
        break;
    default:
    {
        red();
        printf("\nWrong Input");
        reset();
    }
    }
}
void create_data()
{
    char ch = 'Y';
    student_data *data = (student_data *)malloc(sizeof(student_data));
    FILE *fp;
    c_printf("--ADD NEW DATA--");
    if (fopen("files/student.dat", "r") == NULL)
        fp = fopen("files/student.dat", "w");
    else
        fp = fopen("files/student.dat", "a");
    while (toupper(ch) == 'Y')
    {
        printf("\nEnter Student Reg no:");
        fflush(stdin);
        scanf("%ld", &data->reg_no);
        printf("Enter Student Name:");
        fflush(stdin);
        fgets(data->name, 50, stdin);
        printf("\nEnter Student Stream");
        fflush(stdin);
        fgets(data->stream, 10, stdin);
        printf("\nEnter Student Sem");
        fflush(stdin);
        scanf("%hd", &data->sem);
        fwrite(data, sizeof(student_data), 1, fp);
        printf("\nDo you want to add more ?(Y/n)");
        fflush(stdin);
        ch=getc(stdin);
    }
}