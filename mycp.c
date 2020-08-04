#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    int fd1 = 0, fd2 = 0, size = 0, num = 0;
    char buf[128] = {0}, file[50] = {0};
    //int fd[(argc - 2) * 2];
    if (argc < 3) {
        printf("string entered error...\n");
        return 1;
    }
    if (strstr(argv[argc - 1], "/")) {
        for (num = 1; num <= argc - 2; num++) {
            fd1 = open(argv[num], O_RDONLY);
            if (fd1 == -1) {
                perror("open(argv[num])");
                return 4;
            }
            //num++;
            memset(file, 0, 50);
            strcat(file, argv[argc - 1]);
            fd2 = open(strcat(file, argv[num]), O_WRONLY | O_CREAT | \
                    O_EXCL, 0664);
            if (fd2 == -1) {
                perror("open(file)");
                close(fd1);
                return 5;
            }
            while (1) {
                size = read(fd1, buf, 128);
                if (!size) {
                    break;
                }
                write(fd2, buf, size);
            }
            close(fd1);
            close(fd2);
            //num++;
        }
        return 0;
    }
    if (argc == 3) {
        fd1 = open(argv[1], O_RDONLY);
        if (fd1 == -1) {
            perror("open(argv[1])");
            return 2;
        }
        fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0664);
        if (fd2 == -1) {
            perror("open(argv[2])");
            close(fd1);
            return 3;
        }
        while (1) {
            size = read(fd1, buf, 128);
            if (!size) {
                break;
            }
            write(fd2, buf, size);
        }
        close(fd1);
        close(fd2);
        return 0;
    }
    printf("Order entered error...\n");
    return 6;
}
