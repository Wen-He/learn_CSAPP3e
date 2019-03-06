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

int main(int args, char *argv[]) {
    assert(is_little_endian());
    printf("This machinema is little endian.\n");
    return 0;
}