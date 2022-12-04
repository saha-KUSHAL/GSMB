#include "system.h"

struct entered_data
{
    long int password;
    char id[20];
};
void create_login()
{
    FILE *fp;
    if(mt_file("files/user.bin"))
    {
        fp=fopen("/files/user.bin","w");
    }
    else{
        fp=fopen("/files/user.bin","a");

    }
}

enum state login()
{
    struct entered_data *input;
    input = (struct entered_data *)malloc(sizeof(struct entered_data));

    FILE *fp;

    fp = fopen("/files/user.bin", "r");
    if (mt_file("files/user.bin"))//cheking if there is data or not;
    {
        printf("\nNo Admin Found.");
        printf("\nCreate an admin:");
        create_login();
    }
    else
    {
        printf("Enter user name:");
        gets(input->id);
        printf("Enter password:");
        scanf("%ld", &input->password);

        fread(&det, sizeof(det), 1, fp);
        rewind(fp);
        while (!feof(fp))
        {
            if (input->id == det.id)
            {
                if (input->password == det.password)
                {
                    printf("\nAuthorization Sucessfull.");
                    return pass;
                }
                else
                {
                    printf("\nPassword didn't match.");
                    return fail;
                }
            }
            else
                fread(&det, sizeof(det), 1, fp);
        }
    }
    fclose(fp);
    free(input);
}