#include <stdio.h>
#include <assert.h>

int int_shift_are_arithmetic() {
    size_t w = sizeof(int) << 3;
    int test = 1 << (w - 1);
    return !~(test >> (w - 1));
/*
    int test = -1;
    return !(test ^ (test >> 1));
*/
}

int main(int args, char *argv[]) {
    assert(int_shift_are_arithmetic());
    printf("Successful.\n");
    return 0;   
}