#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#pragma pack(1)

struct Student
{
    int rollno;
    char name[20];
    int marks;
    int age;
};

int main(int argc, char *argv[])
{
    int fd = 0;
    struct Student sobj;

    sobj.rollno = 11;
    sobj.marks = 99;
    sobj.age = 19;
    strcpy(sobj.name,"Kaushal");

    fd = creat(argv[1],0777);

    write(fd,&sobj,sizeof(sobj)); 
       
    return 0;
}