#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int lsoct(char* str){
        int ltoo[4] = {0};
        for(int i=0; i<=8; i++){
                if(str[i] == 'r')
                        ltoo[i/3+1] += 4;
                else if(str[i] == 'w')
                        ltoo[i/3+1] += 2;
                else if(str[i] == 'x')
                        ltoo[i/3+1] += 1;
        }
        printf("%d%d%d%d\n", ltoo[0],ltoo[1],ltoo[2],ltoo[3]);
        return 0;
}

char* octls(char* ar){
    char* otol = (char*) malloc(10);
        int arr[3] = {ar[1]-'0', ar[2]-'0',ar[3]-'0'};
        for(int i=0; i<3; i++){
                if(arr[i] == '0'){
                        strcat(otol, "---");
                }else if(arr[i] == '1'){
                       strcat(otol, "--x");
                }else if(arr[i] == 2){
                        strcat(otol, "-w-");
                }else if(arr[i] == 3){
                        strcat(otol, "-wx");
                }else if(arr[i] == 4){
                        strcat(otol, "r--");
                }else if(arr[i] == 5){
                        strcat(otol, "r-x");
                }else if(arr[i] == 6){
                        strcat(otol, "rw-");
                }else if(arr[i] == 7){
                        strcat(otol, "rwx");
                }
        }
        return otol;
}

int main(){
        lsoct("rwxr-xr-x");
        lsoct("rwxrwxrwx");
        printf("%s\n",octls("0755"));
        printf("%s\n",octls("0777"));
}