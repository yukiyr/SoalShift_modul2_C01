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
    struct stat baca;

    time_t raw;
    time(&raw);

    char file[100], sehat[100];
    strcpy(file, "/home/elang/Documents/makanan/makan_enak.txt");

    stat(file, &baca);

    int last = (int)difftime(raw, baca.st_atime);

    if (last <= 30)
    {
      sprintf(sehat, "/home/elang/Documents/makanan/makan_sehat%d.txt", angka);
      FILE *fsehat;
      fsehat = fopen(sehat, "w");
      fclose(fsehat);
      angka++;
    }
    sleep(5);
  }

  exit(EXIT_SUCCESS);
}
