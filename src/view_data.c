#include "system.h"
void view_data()
{
    int ch;
    yellow();
    c_printf("--VIEW DATA--");
    blue();
    printf("\n----------\t\t\t------------\t\t\t---------");
    printf("\n|(1)Streams|\t\t\t|(2)Student|\t\t\t|(0)Exit|");
    printf("\n----------\t\t\t------------\t\t\t---------");
    reset();
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        stream();
        break;
    case 2:
        student();
        break;
    case 0:
        exit(0);

    default:
        break;
    }
}
void stream()
{
    FILE *fp;
    fp = fopen("files/stream.txt", "r");
    if (!ferror(fp) && fopen("files/stream.txt", "r") == NULL)
    {
        red();
        printf("\nERROR!");
        reset();
    }
    else if (mt_file("files/stream.txt"))
    {
        red();
        printf("\nNo data available!");
        reset();
    }
    else
    {
        stream_data *data;
        data = (stream_data *)malloc(sizeof(stream_data));
        rewind(fp);
        fread(data, sizeof(stream_data), 1, fp);
        while (!feof(fp))
        {
            printf("\nSerial No.   Stream Name      No. of Semester");
            printf("\n%d            %s                 %d", data->scount, data->sname, data->sem);
            fread(data, sizeof(stream_data), 1, fp);
        }

        free(data);
        fclose(fp);
    }
}
void student()
{
    FILE *fp;
    fp = fopen("files/student.dat", "r");
    if ((!ferror(fp)) && (fopen("files/student.txt", "r") == NULL))
    {
        red();
        printf("\nERROR!");
        reset();
    }
    else if (mt_file("files/student.dat"))
    {
        red();
        printf("\nNo data available!");
        reset();
    }
    else
    {
        int ch;
        printf("\nPress 1 to enter Registration no.\nPress 2 for View by STREAM and SEMESTER");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            long int regno;
            printf("\nEnter REG. No:");
            scanf("%ld",&regno);
            search_student_data(regno);
            break;
        case 2:
            break;
        default:
            red();
            printf("\nWrong input");
            reset();
        }
    }
    fclose(fp);
}