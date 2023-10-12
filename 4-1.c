#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int my_double_ls(const char *name, int skip){
    struct dirent *d;
    DIR *dp;

    if((dp=opendir(name)) == NULL)
        return -1;
    
    if(skip){
         while(d = readdir(dp)){
            if(d->d_ino != 0 && d->d_name[0] != '.')
                printf("%s\n", d->d_name);
         }
    }else{
        while(d = readdir(dp)){
            if(d->d_ino != 0)
                printf("%s\n", d->d_name);
        }
        rewinddir(dp);
        while(d = readdir(dp)){
            if(d->d_ino != 0)
                printf("%s\n", d->d_name);
        }
    }

    closedir(dp);
    return 0;
}

int main(int argc, char* argv[]){
    my_double_ls(argv[1], atoi(argv[2]));
}