#include <stdio.h>
#include <string.h>
#include <wait.h>

#define N 2
#define LEN 100

int main(int argc, char *argv[]) {
    int i, status;
    pid_t pid;

    for (i = 0; i < N; i++) {
        if ((pid = fork()) == 0) {
            char *cptr = NULL;
            *cptr = "write";
        }
    }

    while((pid = wait(-1, &status, 0)) > 0) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status %d\n",
                pid, WEXITSTATUS(status));
        else if (WIFSIGNALED(status)) {
            char buf[LEN];
            sprintf(buf, "child %d terminated by signal %d", pid, WTERMSIG(status));
            psignal(WTERMSIG(status), buf);
        }
        else
            printf("child %d terminated abnormally\n", pid);
    }

    if (errno != ECHILD)
        exit(1);
    exit(0);
}
