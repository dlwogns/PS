#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int my_double_ls(const char *name) {
    struct dirent *d;
    struct stat stats;
    DIR *dp;

    if ((dp = opendir(name)) == NULL)
        return -1;

    while ((d = readdir(dp)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", name, d->d_name);

        if (stat(path, &stats) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(stats.st_mode)) {
            printf("%s* ", d->d_name);
        } else {
            printf("%s ", d->d_name);
        }
    }
    

    printf("%c", '\n');
    rewinddir(dp);

    while ((d = readdir(dp)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", name, d->d_name);

        if (stat(path, &stats) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(stats.st_mode)) {
            printf("%s* ", d->d_name);
        } else {
            printf("%s ", d->d_name);
        }
    }

    closedir(dp);
    return 0;
}

int main(int argc, char *argv[]) {
    my_double_ls(argv[1]);
    return 0;
}
