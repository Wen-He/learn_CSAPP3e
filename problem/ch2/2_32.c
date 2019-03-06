#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main() {
    int y = INT_MIN;
    printf("y = %d, -y =  %d\n", y, -y);
    show_int(y);
    show_int(-y);
    return 0;
}

/* 
If y = INT_MIN, then -y = INT_MIN too.
Assuming w = 4, then INT_MIN = -8 [1000], -y = 8 [1000].
This explains my doubt (line 26).
*/