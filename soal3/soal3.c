#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int p[2];
int r;

int main() {
  pid_t child_id;
  pid_t child_id_2;
  pid_t child_id_3;
  int status;

  FILE *out_file = fopen("daftar.txt","w");
  child_id = fork();

  if (child_id == 0) {
    // this is first child
        char *argv[3] = {"touch", "daftar.txt", NULL};
        execv("/usr/bin/touch", argv);

  } else {
    // this is second child
    child_id_2 = fork();
    if (child_id_2 == 0) {
        char *argv[3] = {"unzip", "campur2.zip", NULL};
        execv("/usr/bin/unzip", argv);

    } else {
      while ((wait(&status)) > 0);

        char *ls[] = {"ls", "campur2", NULL};
        char *grep[] = {"grep", ".*.txt$", NULL};

        pipe(p);
        child_id_3=fork();
        if (child_id_3 !=0) {
                dup2(p[1],1);
                close(p[0]);
                r=execvp("ls",ls);
        } else {
                dup2(p[0],0);
                close(p[1]);
                r=execvp("grep",grep);
                close(p[0]);
        }
        fprintf(out_file,"%d",r);
    }
  }
}
