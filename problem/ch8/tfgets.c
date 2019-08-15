#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

#define LEN 100

sigjmp_buf buf;

void alarm_handler(int sig) {
    siglongjmp(buf, 1);
}

char* tfgets(char* s, int size, FILE* stream) {
    char* result;

    if (!sigsetjmp(buf, 1)) {
        alarm(5);
        if (signal(SIGALRM, alarm_handler) == SIG_ERR)
            exit(1);
        return fgets(s, size, stream);
    } else {
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    char buf[LEN];
    char *input = tfgets(buf, LEN, stdin);

    if (input == NULL)
        printf("no input\n");
    else 
        printf("input string: %s", input);
    return 0;
}