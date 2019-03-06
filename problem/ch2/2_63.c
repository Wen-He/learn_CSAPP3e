#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    // set high k bit to 0 without >> and /
    size_t w = sizeof(int) << 3;
    unsigned mask = (1 << (w - k)) - 1;
    return xsra & mask;
}

unsigned sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    // set high k bit same with (w-k)th bit without >> and /
    size_t w = sizeof(int) << 3;
    int mask = (int) -1 << (w - k);
    int s = 1 << (w - 1);
    mask &= !(x & s) - 1; // *** distinguish ~ and ! *** //
    return xsrl | mask;
}

int main() {
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    printf("Successful.\n");
    return 0;
}