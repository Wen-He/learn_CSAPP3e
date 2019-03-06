#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);
    printf("\n");
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

int main() {
    float f = 1.0e15;
    double d = 1.0;
    printf("%f:  ", f);
    show_float(f);
    printf("%f:  ", d);
    show_double(d);
    printf("%d\n", (f+d) - f == d);
    printf("f+d = %f\n", f + d);
    return 0;
}

/*
当f的阶码大于52时，相加时，对阶过程中double(d = 1.0)可能会变成0。
*/