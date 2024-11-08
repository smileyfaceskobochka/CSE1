#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zero(unsigned int x, int n) {
    if (x < 0 || x >= (1U << n)) {
        printf("ошибка");
    } else {
        for (int i = n - 1; i >= 0; i--) {
            putchar((x & (1U << i)) ? '1' : '0');
        }
    }  
}

void one(int x, int n) {  
    int mask = 1 << (n - 1);

    if (x < -(1 << (n - 1)) || x >= (1 << (n - 1))) {
        printf("ошибка");
    } else {
        if (x < 0) x = ~x + 1;
        for (int i = 0; i < n; i++) {
            putchar(x & mask ? '1' : '0');
            mask >>= 1;
        }
    }
}

void three(int x, int n) {    
    int mask = 1 << (n - 1);

    if (x < -(1 << (n - 1)) || x >= (1 << (n - 1))) {
        printf("ошибка");
    } else {
        if (x < 0) {
            for (int i = 0; i < n; i++) {
                putchar(x & 1 ? '0' : '1');
                x >>= 1;
            }
        } else {
            for (int i = 0; i < n; i++) {
                putchar(x & 1 ? '1' : '0');
                x >>= 1;
            }
        }
    }

    
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);

    printf("0. ");
    zero(x, n);
    putchar('\n');
    printf("1. ");
    one(x, n);
    putchar('\n');
    printf("2. ");
    three(x, n);
    return 0;
}