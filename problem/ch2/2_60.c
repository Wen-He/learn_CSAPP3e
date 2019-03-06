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

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    assert(i >= 0 && i <= sizeof(unsigned) - 1);
    if(is_little_endian() == 0)
        i = sizeof(unsigned) - 1 - i;
    byte_pointer pos = (byte_pointer) &x;
    pos[i] = b;
    return x;
/* 
Bit operation:
    unsigned mask = ((unsigned) 0xFF) << (i << 3);
    unsigned pos_byte = ((unsigned) b) << (i << 3);

    return (x & ~mask) | pos_byte;
*/
}
int main(int args, char *argv[]) {
    assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);
    printf("Successful!\n");
    return 0;
}

