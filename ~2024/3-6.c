#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char *filename = "afile";

    if(access(filename, R_OK) == -1){
        fprintf(stderr, "User cannon read file %s\n", filename);
    }else
        printf("%s readable, proceeding\n", filename);

    if(access(filename, W_OK) == -1){
        fprintf(stderr, "User cannon write file %s\n", filename);
    }else
        printf("%s writeable, proceeding\n", filename);

    if(access(filename, X_OK) == -1){
        fprintf(stderr, "User cannon execute file %s\n", filename);
    }else
        printf("%s executable, proceeding\n", filename);
    
}