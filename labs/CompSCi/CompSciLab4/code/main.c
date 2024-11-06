#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int printBinary(unsigned int x, int n) {
    if (x < 0 || x >= (1U << n)) {
        printf("ошибка\n");
        return -1;
    }

    for (int i = n - 1; i >= 0; i--) {
        putchar((x & (1U << i)) ? '1' : '0'); // Е
    }
    return 0;
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);

    printBinary(x, n);
    return 0;
}