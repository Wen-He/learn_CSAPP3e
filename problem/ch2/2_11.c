#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    printf("Step 1: x = %d, y = %d\n", *x, *y);
    *x = *x ^ *y;
    printf("Step 2: x = %d, y = %d\n", *x, *y);
    *y = *x ^ *y;
    printf("Step 3: x = %d, y = %d\n", *x, *y);
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first <= last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

void init_array(int a[], int cnt) {
    int i;
    for (i = 0; i < cnt; i++)
        a[i] = i + 10;
}

void show_array(int a[], int cnt) {
    int i;
    for (i = 0; i < cnt; i++) 
        printf("%d  ", a[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n;
    if (argc > 1) {
        n = strtol(argv[1], NULL, 0);
        int *a = malloc(n * sizeof(int));
        printf("initial array: ");
        init_array(a, n);
        show_array(a, n);
        reverse_array(a, n);
        printf("after reverse: ");
        show_array(a, n);
        free(a);
    }
    return 0;
}

/* 
When the x and y point to the same element in an array,
they will both become 0 after executing line 5.
I did not realize this when I first see this exercise.
*/