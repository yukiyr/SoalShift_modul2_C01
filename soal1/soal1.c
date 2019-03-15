#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

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

  if ((chdir("/home/test")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
        pid_t child_id, child_id_2;
        int status;

        child_id = fork();

        if (child_id == 0) {
        // this is child

        char *argv[4] = {"mkdir", "-p", "modul2/gambar", NULL};
        execv("/bin/mkdir", argv);
        } else {
        // this is second child
        child_id_2 = fork();
        if (child_id_2 == 0) {

        char *argv[4] = {"mkdir", "-p", "modul2", NULL};
        execv("/bin/mkdir", argv);

        } else {
        while ((wait(&status)) > 0);
        char filename[10000];
        char filename2[10000];
        char filename3[10000];
        char awal1[10000];
        char akhir1[10000];
        char *pointer;
        char *pointer1;
        char *pointer2;
        char *pointer3;

        DIR *direktori;
        struct dirent *dir;
        direktori = opendir("/home/test/");
        if (direktori)
        {
                while ((dir = readdir(direktori)) != NULL)
                {
                        strcpy(filename,dir->d_name);
                        pointer3 = strrchr(filename, '.');
                        strcpy(filename3,filename);
                        if (pointer3 && (strcmp(pointer3, ".png") == 0))
                        {
                                *pointer3 = '\0';
                                strcpy(filename2,filename);
                                pointer = filename2;
                                char tambahan[10]="_grey.png";
                                strcat (pointer,tambahan);
                                char awal[]="/home/test/";
                                char akhir[]="/home/test/modul2/gambar/";
                                strcpy(awal1,awal);
                                strcpy(akhir1,akhir);
                                pointer1 = awal1;
                                pointer2 = akhir1;
                                strcat (pointer1,filename3);
                                strcat (pointer2,pointer);
                                rename (pointer1,pointer2);
                        }
                }
                closedir(direktori);
        }
      }
    }
  }
  exit(EXIT_SUCCESS);
}
