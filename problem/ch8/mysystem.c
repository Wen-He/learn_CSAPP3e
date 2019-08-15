#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int mysystem(char *command) {
    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        execve("/bin/sh", command, environ);
    }
    printf("Child pid: %d\n", pid);

    if (waitpid(pid, &status, 0) > 0) {
        if (WIFEXITED(status))
            return WEXITSTATUS(status);

        if (WIFSIGNALED(status))
            return WTERMSIG(status);
    }
}

int main(int argc, char *argv[]) {
    int code = mysystem(argv[1]);
    printf("The return code: %d\n", code);
    return 0;
}