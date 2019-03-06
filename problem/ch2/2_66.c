#include <stdio.h>
#include <assert.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x & 0x01); // if x = 0, it won't plus 1
}

int main(int argc, char* argv[]) {
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x6000) == 0x4000);
    assert(leftmost_one(0x0) == 0x0);
    assert(leftmost_one(0x80000000) == 0x80000000);

    printf("Successful.\n");
    return 0;
}