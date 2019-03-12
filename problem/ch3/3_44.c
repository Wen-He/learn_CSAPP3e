#include <stdio.h>

struct P2 {
    int i;
    char c;
    char d;
    long j;
};

struct P3 {
    short w[3];
    char c[3];
};

struct P5 {
    struct P3 a[2];
    struct P2 t;
    
};

int main() {
    struct P5 s5;
    printf("%lu\n", sizeof(struct P2));
    printf("%lu\n", sizeof(struct P3));
    printf("%lu\n", sizeof(struct P5));
    printf("%lu\n", sizeof(s5.a));
    printf("%lu\n", sizeof(s5.t));
    printf("%p\n", s5.a);
    printf("%p\n", &s5.t);
    return 0;
}