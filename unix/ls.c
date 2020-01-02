#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *dirent;

    if (argc != 2) {
      printf("usage: ls directory name!");
      exit(0);
    }

    if ((dir = opendir(argv[1])) == NULL) {
      printf("Cannot open %s", argv[1]);
      exit(127);
    }
    while ((dirent = readdir(dir)) != NULL)
      printf("%s\n", dirent->d_name);

    closedir(dir);
    return 0;
}
