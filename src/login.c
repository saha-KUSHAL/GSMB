#include "system.h"

struct entered_data
{
    long int password;
    char id[20];
};

enum state login()
{
    struct entered_data *input;
    input = (struct entered_data *)malloc(sizeof(struct entered_data));

    FILE *fp;

    fp = fopen("/files/user.bin", "r");
    fseek(fp, 0, 2);
    if (ftell(fp) == 0)//cheking if there is data or not;
    {
        printf("\nNo Admin Found.");
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
}