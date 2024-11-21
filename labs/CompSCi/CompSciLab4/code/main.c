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

char* two(int x, int n) {
    char *arr = (char*)malloc(sizeof(char) * (n + 1));

    if (x < -(1 << (n - 1)) || x >= (1 << (n - 1))) {
        printf("ошибка: число %d выходит из диапазона представления в дополнительном коде для сетки %d\n", x, n);
        free(arr);
        return NULL;
    }

    int mask = 1 << (n - 1);

    for (int i = 0; i < n; i++) {
        arr[i] = (x & mask) ? '1' : '0';
        mask >>= 1;
    }

    arr[n] = '\0';
    
    free(arr);
    return arr;
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

int four(int x, int y, int n) {
    char* str1 = two(x, n); 
    char* str2 = two(y, n);

    if (str1 == NULL || str2 == NULL){
        printf("че?");
        return -1;
    }

    int dist = 0;

    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            dist++;
        }
    }

    return dist;
}

int main() {
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);

    zero(x, n);
    one(x, n);
    printf("2. %s (дополнительный код)\n", two(x, n));
    three(x, n);
    printf("4. %d (расстояние по хэммингу)", four(x, y, n));
    return 0;
}