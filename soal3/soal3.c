#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
  int p[2];
  int q[2];

  pid_t child_id;
  pid_t child_id_2;
  pid_t child_id_3;
  pid_t child_id_4;
  int status;
  int r;
  char tampungan[10000]={0};

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
        pipe(q);
        child_id_3=fork();
        if (child_id_3 == 0) {
                //this is third child
                dup2(p[1],1);
                close(p[0]);
                close(p[1]);
                execvp("ls", ls);
        } else {
                child_id_4 = fork();
                if (child_id_4 == 0) {
                        //this is fourth child
                        dup2(p[0],0);
                        dup2(q[1],1);
                        close(p[1]);
                        close(p[0]);
                        close(q[1]);
                        close(q[0]);
                        execvp("grep", grep);
                } else {
                        close(p[0]);
                        close(p[1]);
                        close(q[1]);
                        r = read(q[0],tampungan,sizeof(tampungan));
                        FILE *out_file = fopen("daftar.txt","w+");
                        fprintf(out_file,"%.*s\n", r, tampungan);
                }
        }
    }
  }
}
