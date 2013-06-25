#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
//#include "figB.3"

#include<time.h> 
#define D (24*60*60)
#define H (60*60)
#define M (60)

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
        printf("authority	UID	GID	size	modifingtime	filename\n");
        while ((dirp = readdir(dp)) != NULL){
            stat("dirp -> d_name", &buf);
 
            time(&(buf.st_mtime)); 
            long time = buf.st_mtime % D;
            int h = time / H;
            time = time % H;
            int m = time / M;
            time = time % M;
            int s = time;

            printf("%d	%d	%d	", buf.st_mode, buf.st_uid, buf.st_gid);
            printf("%ld	%02d:%02d:%02d	%s	", buf.st_size, h, m, s, dirp ->d_name);
            printf("\n");
            //printf("%d", sizeof(off_t));
        }
        printf("\n");
        exit(0);
        }

//ls -t filename
        case 't' :{
        
        }

//ls -r filename
        case 'r' :{
        if ((dp = opendir(argv[2])) == NULL){
            printf("can't open %s\n", argv[1]);
            exit(0);
        }
        int count = 0;
        while ((dirp = readdir(dp)) != NULL)
            ++count;
        char *buffer[count];
        int i = 0;
        while ((dirp = readdir(dp)) != NULL){
            buffer[i] = dirp -> d_name;
            i ++;
        }
        int comp(const void *a, const void *b){
            return (*(int *)a - *(int *)b);
        }
        qsort(buffer[count], count, sizeof(long) * 50, comp);
        i = 0;
        while (i < count){
            printf("%s	", buffer[i]);
            i ++;
        }
        }

//ls -a filename
        case 'a' :{
        if ((dp = opendir(argv[2])) == NULL){
            printf("can't open %s\n", argv[1]);
            exit(0);
        }
        while ((dirp = readdir(dp)) != NULL)
            printf("%s  ", dirp -> d_name);
        printf("\n");
        exit(0);
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
