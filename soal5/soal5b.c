#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    char *argv[3] = {"pkill", "soal5", NULL};
    execv("/usr/bin/pkill", argv);
}
