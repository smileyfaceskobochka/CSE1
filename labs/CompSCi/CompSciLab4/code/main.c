#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zero(unsigned int x, int n) {
    printf("0. ");
    if (x >= (1U << n)) {
        printf("ошибка: число %d не входит в диапазон представления для сетки %d.\n", x, n);
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        putchar((x & (1U << i)) ? '1' : '0');
    }
    putchar('\n');
}

void one(int x, int n) {
    printf("1. ");
    if (x <= -(1 << (n - 1)) || x >= (1 << (n - 1))) {
        printf("ошибка: число %d выходит из диапазона представления в прямом коде для сетки %d.\n", x, n);
        return;
    }

    if (x < 0) {
        putchar('1');
        x = -x;
    } else {
        putchar('0');
    }

    for (int i = n - 2; i >= 0; i--) {
        putchar((x & (1U << i)) ? '1' : '0');
    }

    printf(" (прямой код)\n");
}

void two(int x, int n) {
    printf("2. ");

    if (x < -(1 << (n - 1)) || x >= (1 << (n - 1))) {
        printf("ошибка: число %d выходит из диапазона представления в дополнительном коде для сетки %d\n", x, n);
        return;
    }

    int mask = 1 << (n - 1);

    for (int i = n - 1; i >= 0; i--) {
        putchar((x & mask) ? '1' : '0');
        mask >>= 1;
    }

    printf(" (дополнительный код)\n");
}

void three(int x, int n) {
    printf("3. ");
    if (x >= (1 << n)) {
        printf("ошибка: число %d не входит в диапазон представления для сетки %d.\n", x, n);
        return;
    }

    if (x < 0) {
        x = -x;
        for (int i = n - 1; i >= 0; i--) {
            putchar((x & (1U << i)) ? '0' : '1');
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            putchar((x & (1U << i)) ? '1' : '0');
        }
    }
    printf(" (обратный код)\n");
}

void four(int x, int n) {
    printf("4. ");

    putchar('\n');
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);

    zero(x, n);
    one(x, n);
    two(x, n);
    three(x, n);
    four(x, n);
    return 0;
}