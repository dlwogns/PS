#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

struct stat stats;

void slowwatch(const char *filename, time_t lasttime){
    if(stat(filename, &stats) == -1 || stats.st_mtime != lasttime){
        int fd = open(filename, O_RDONLY);
        int sizet;
        char buffer[10];
        printf("file changed");
        if(fd > 0){
            while((sizet = read(fd, buffer, 9)) > 0){
                buffer[sizet] = 0;
                puts(buffer);
            }
            close(fd);
        }
    }else{
        printf("open error\n");
    }
}
int main(int argc, char* argv[]){
    time_t lasttime;
    if(stat(argv[1], &stats) == -1){
        perror("stat error\n");
        return 0;
    }
    lasttime = stats.st_mtime;
    for(;;){
        slowwatch(argv[1], lasttime);   
        sleep(5);
    }
}