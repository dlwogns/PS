#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int lsoct(char* str){
        int ltoo[4] = {0}, oc = 0, mcheck = 64;
        for(int i=0; i<=8; i++){
                if(str[i] == 'r')
                        ltoo[i/3+1] += 4;
                else if(str[i] == 'w')
                        ltoo[i/3+1] += 2;
                else if(str[i] == 'x')
                        ltoo[i/3+1] += 1;
            if(i%3 == 2){
                oc += mcheck*ltoo[i/3+1];
                mcheck = mcheck / 8;
            }
        }
        
        return oc;
}

int main(int argc, char* argv[]){
    if(strlen(argv[2]) == 9){
        int oc = lsoct(argv[2]); 
        if(chmod(argv[1], oc) == -1)
            perror("chmod failed\n");
    }else{
        int oc = strtol(argv[2], 0, 8);
        if(chmod(argv[1], oc) == -1)
            perror("chmod failed\n");
    }
    return 0;

}