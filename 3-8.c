#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int check = access(argv[1], W_OK);
    if(check != -1){
        printf("You have write permission\n");
        return 0;
    }else{
        perror("You don't have write permission\nDo you want unlink this file?\n(yes = 1, No = 0)\n");
        int input; scanf("%d", &input);
        if(input == 1){
            if(unlink(argv[1]) == -1)
                perror("unlink error\n");
        }
    }
    
}