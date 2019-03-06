#include <stdio.h>
#include <assert.h>

typedef unsigned char *byte_pointer;

int is_little_endian() {
    int test = 0xff;
    byte_pointer start = (byte_pointer) &test;
    if (start[0] == 0xff)
        return 1;
    return 0;
}

int word_generator(int x, int y, int little_endian) {
    byte_pointer tail_x = (byte_pointer) &x;
    byte_pointer tail_y = (byte_pointer) &y;
    if (little_endian == 0) {
        size_t len = sizeof(int);
        tail_y[len - 1] = tail_x[len - 1];
        return y;
    }
    tail_y[0] = tail_x[0];
    return y;
/*
Bit operation:
    int mask = 0xFF;
    return (x & mask) | (y & ~mask);
*/
}

int main(int args, char *argv[]) {
    int s = is_little_endian();
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int z = word_generator(x, y, s);
    assert(z == 0x765432EF);
    printf("Successful!\n");
    return 0;
}