#include "system.h"


void create_login()
{

    details *data; // pointer variable of details structure
    data = (details *)malloc(sizeof(details));
    FILE *fp;
    if (mt_file("files/user.dat"))
    {
        fp = fopen("files/user.dat", "w");
    }
    else
    {
        fp = fopen("files/user.dat", "a");
    }
    printf("\nEnter User Name:");
    fflush(stdin);
    fgets(data->id, 20, stdin);
    printf("\nCreate a Password:");
    fflush(stdin);
    fgets(data->password, 20, stdin);
    fwrite(data, sizeof(details), 1, fp);
    fclose(fp);
    free(data);
}

test login()
{
    int n, flag = 0;
    if (mt_file("files/user.dat")) // cheking if there is data or not;
    {
        printf("\nNo Admin Found.");
        printf("\nCreate an admin:");
        printf("\nPress 1 to create an admin account.\nPress any key to go back.\n");
        if (scanf("%d", &n) == 1)
        {
            create_login();
            return pass;
        }
        else
            return fail; // have to chnage this.
    }
    else
    {
        details *data = (details *)malloc(sizeof(details));
        entered_data *input = (entered_data *)malloc(sizeof(entered_data));

        FILE *fp = fopen("files/user.dat", "r");

        printf("\nEnter User Name:");
        fflush(stdin);
        fgets(input->id, 20, stdin);

        printf("\nEnter Password:");
        fflush(stdin);
        fgets(input->password, 20, stdin);

        rewind(fp);
        fread(data, sizeof(details), 1, fp);

        while (!feof(fp))
        {
            if (strcmp(input->id,data->id)==0)
            {
                if (strcmp(input->password,data->password)==0)
                {
                    printf("\nAuthorization Sucessfull.");
                    return pass;
                }
                else
                {
                    printf("\nPassword didn't match.");
                    return fail;
                }
                flag = 1;
            }
            else
                fread(data, sizeof(details), 1, fp);
        }
        free(input);
        free(data);
        fclose(fp);
    }
    if (flag == 0)
    {
        printf("\nUser not Found");
        return fail;
    }
}