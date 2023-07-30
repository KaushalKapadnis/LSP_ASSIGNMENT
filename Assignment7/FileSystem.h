#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

bool FileCmp(char file1[50], char file2[50]);