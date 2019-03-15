#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main() {
    pid_t pid, sid;
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    int angka = 1;
    while(1) {
        time_t raw;
        struct tm *timeinfo;
        char tanggal[40], path[80];
        time(&raw);
        timeinfo = localtime(&raw);
        strftime(tanggal, sizeof(tanggal), "%d:%m:%Y-%H:%M", timeinfo); 
        sprintf(path, "/home/elang/log/%s/", tanggal);
        mkdir(path, S_IRWXU | S_IRWXO | S_IRWXG);
        
        for(int i = 0; i < 30 ; i++){
            char file[50], path2[80];
            strcpy(path2,path);
            sprintf(file, "log%d.log", angka);
            strcat(path2, file);

            FILE *fwrite, *fread;
            fread = fopen("/var/log/syslog", "r");
            fwrite = fopen(path2,"w+");

            char ch;

            if(fread != NULL && fwrite != NULL){
            while ((ch = fgetc(fread)) != EOF)
                fputc(ch, fwrite);

            fclose(fwrite);
            }
            angka++;
            sleep(60);
        }

    }
    exit(EXIT_SUCCESS);
}
