#include <stdio.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n) {
    size_t w = sizeof(int) << 3;
    return x << n | x >> (w - n);
}

int main(int argc, char* argv[]) {
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);

    printf("Successful.\n");
    return 0;
}