#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)

struct Student
{
    int rollno;
    char name[20];
    int marks;
    int age;
};

int main(int argc,char *argv[])
{
    int fd = 0,ret = 0;
    struct Student sobj;

    if(argc != 2)
    {
        printf("Invalid Arguments");
        return 0;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open File\n");
        return -1;
    }

    ret = read(fd,&sobj,sizeof(sobj));
    if(ret == -1)
    {
        printf("Unable to read File\n");
        return -1;
    }

    printf("%s\n",sobj.name);
    printf("%d\n",sobj.rollno);
    printf("%d\n",sobj.marks);
    printf("%d\n",sobj.age);

    return 0;
}