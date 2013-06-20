#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
//#include "figB.3"

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    struct stat buf; //buffer the stat of direction

//the commend is "myls"
    if (argc == 1){
        if ((dp = opendir(".")) == NULL){
            printf("can't open current direction\n");
            exit(0);
        }
        while ((dirp = readdir(dp)) != NULL)
            printf("%s	", dirp -> d_name);
        printf("\n");
        exit(0);
    }

//the commend is "myls filename"
    if (argc == 2){
        if ((dp = opendir(argv[1])) == NULL){
            //err_sys("can't open %s", argv[1]);
            printf("can't open %s", argv[1]);
            exit(0);
        }
        while ((dirp = readdir(dp)) != NULL)
            printf("%s	", dirp -> d_name);
        printf("\n");
        //printf("argv[1] = %s", argv[1]);
        exit(0);
    }

//the commend is "myls -option filename"
    if (argc == 3){
        switch (*(argv[1] + 1))
        {
//ls -l filename
        case 'l' :{
        //printf ("%s\n", argv[1]); exit(0);
        if ((dp = opendir(argv[2])) == NULL){
        printf("can't open %s", argv[1]);
        exit(0);
        }
        while ((dirp = readdir(dp)) != NULL){
            stat("dirp -> d_name", &buf);
            printf("%d	%d	%d	", buf.st_mode, buf.st_uid, buf.st_gid);
            printf("%d	%d	%s	", buf.st_size, buf.st_mtime, dirp ->d_name);
            printf("\n");
        }
        printf("\n");
        exit(0);
        }

//ls -t filename
        case 't' :{
                
        }

//commend is wrong
        defaule : exit(0);
        }
    }

//the commend is wrong
    else{
        //err_quit("usage:myls directory_name");
        printf("usage:myls directory_name\n");
        printf("argc = %d", argc);
    }
}
