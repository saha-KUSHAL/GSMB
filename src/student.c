// function to store student marks by stream and semester
#include "system.h"
void create_data()
{
    char ch = 'Y';
    student_data *data = (student_data *)malloc(sizeof(student_data));
    FILE *fp;
    c_printf("--ADD NEW DATA--");
   /*when we are adding new student data, we will add marks too by  add_marks fucntion.
    which will create files with name concating stream and sem names.*/
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
        fgets(data->name, sizeof(data->name), stdin);
        printf("Enter Student Stream:");
        fflush(stdin);
        fgets(data->stream,sizeof(data->stream), stdin);
        printf("Enter Student Sem:");
        fflush(stdin);
        fgets(data->sem,sizeof(data->sem),stdin);
        add_marks(data->reg_no,data->stream,data->sem);//marks of stuents
        fwrite(data, sizeof(student_data), 1, fp);
        printf("\nDo you want to add more ?(Y/n)");
        fflush(stdin);
        ch=getc(stdin);
    }
    free(data);
    fclose(fp);
}
void add_marks(long int reg, char stream[5], char sem[3])
{
    char file_path[30] = "files/database/";
    FILE *fp;
    marks *mark = (marks *)malloc(sizeof(malloc));
    mark->reg=reg;
    strcat(stream, sem);       // ex-bcai or bcavi
    strcat(file_path, stream); // files//database/bcai or files/databse/bcavi
    strcat(file_path, ".dat"); // files//database/bcai.dat or files/databse/bcavi.dat

    if (fopen(file_path, "r") == NULL) // checks file already exists or not
        fp = fopen(file_path, "w");
    else
        fp = fopen(file_path, "a");
    printf("\nPut 0 if there is no subject");
    printf("\nEnter Marks of Sub 1:");
    fflush(stdin);
    scanf("%hd", &mark->subject.sub1);
    printf("Enter Marks of Sub 2:");
    fflush(stdin);
    scanf("%hd", &mark->subject.sub2);
    printf("Enter Marks of Sub 3:");
    fflush(stdin);
    scanf("%hd", &mark->subject.sub3);
    printf("Enter Marks of Sub 4:");
    fflush(stdin);
    scanf("%hd", &mark->subject.sub4);
    printf("Enter Marks of Sub 5:");
    fflush(stdin);
    scanf("%hd", &mark->subject.sub5);
    printf("Enter Marks of Sub 6:");
    fflush(stdin);
    scanf("%hd", &mark->subject.sub6);
    fwrite(mark, sizeof(marks), 1, fp);
    fclose(fp);
    free(mark);
}
