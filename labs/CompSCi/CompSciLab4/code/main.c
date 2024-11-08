#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int zero(unsigned int x, int n) {
    if (x < 0 || x >= (1U << n)) {
        printf("ошибка");
        return -1;
    }

    for (int i = n - 1; i >= 0; i--) {
        putchar((x & (1U << i)) ? '1' : '0');
    }
    return 0;
}

int one(int x, int n) {    
    if (x < -(1 << (n - 1)) || x >= (1 << (n - 1))) {
        printf("ошибка");
        return -1;
    }

    putchar(x < 0 ? '1' : '0');
    
    for (int i = 0; i < n; i++) {
        putchar(x << 1 ? '0' : '1');
    }

    return 0;
}

int three(int x, int n) {    
    if (x < 0 || x >= (1U << n)) {
        printf("ошибка");
        return -1;
    }

    putchar(x < 0 ? '1' : '0');
    
    for (int i = 1; i < n; i++) {
        putchar(x << 1 ? '0' : '1');
    }

    return 0;
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);

    printf("1. ");
    zero(x, n);
    putchar('\n');
    printf("2. ");
    one(x, n);
    putchar('\n');
    printf("3. ");
    three(x, n);
    return 0;
}