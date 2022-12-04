#include "system.h"
enum state test;

struct entered_data
{
    long int password;
    char id[20];
};

int login()
{
    struct entered_data v;
    struct entered_data *input = &v;

    int check = fail;
    FILE *fp;
    printf("Enter user name:");
    gets(input->id);
    printf("Enter password:");
    scanf("%d", &input->password);

    fp = fopen("/files/user.bin", "r");
    fread(&log, sizeof(log), 1, fp);
    while (!feof(fp))
    {
        if (input->id == log.id)
        {
            if (input->password == log.password)
            {
                printf("\nAuthorization Sucessfull.");
                check = pass;
            }
            else
                printf("\nPassword didn't match.");
        }
        else
            fread(&log, sizeof(log), 1, fp);
    }
    fclose(fp);
    return check;
}