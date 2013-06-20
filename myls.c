#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
//#include "figB.3"

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

//the commend is "myls"
    if (argc == 1){
        if ((dp = opendir(".")) == NULL){
            printf("can't open current direction\n");
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
            printf("cna't open %s", argv[1]);
        }
        while ((dirp = readdir(dp)) != NULL)
            printf("%s	", dirp -> d_name);
        printf("\n");
        //printf("argv[1] = %s", argv[1]);
        exit(0);
    }

//the commend is "myls -option filename"
    if (argc == 3){

    }

//the commend is wrong
    else{
        //err_quit("usage:myls directory_name");
        printf("usage:myls directory_name\n");
        printf("argc = %d", argc);
    }
}
