#include <stdio.h>

#define A_LEN 4

void bubble_p(long *data, long count);

int main(int argc, char *argv[]) {
    int i;
    long data_p[A_LEN] = { 1, 4, 3, 2 };

    bubble_p(data_p, A_LEN);

    for (i = 0; i < A_LEN; i++) {
        printf("%ld ", data_p[i]);
    }
    printf("\n");

    return 0;
}