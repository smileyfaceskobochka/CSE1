#include <stdio.h>
#include <math.h>

void print_bin(int n, int b) {
    for (int i = b - 1; i >= 0; i--) {
        printf("%d", n >> i & 1);
    }
}

void print_bin2(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", n >> i & 1);
    }
}

int main() {
    float x; int n, k;
    scanf("%f %d %d", &x, &n, &k);

    int* d = (int*) & x;
    int s = *d >> 31;
    int e = *d >> 23 & (int)pow(2, 8) - 1;
    int m = *d & (int)pow(2, 23) - 1;
    int p = e - (pow(2, 7) - 1);
    int c = p + 1 + pow(2, n - k - 2);
    e = p + (pow(2, n - k - 2) - 1);

    if (k != 23) {
        if (p > 0) {
            m = m / pow(2, k + p);
        } else {
            m = m / pow(2, 23 - k);
        }
    }

    print_bin(s, 1);
    print_bin(e, n - k - 1);
    print_bin(m, k);
    printf("\n");

    m = (m + pow(2, k)) / 2;

    print_bin(s, 1);
    print_bin(m, k);
    printf("%d", p + 1 < 0 ? 1 : 0);
    print_bin(abs(p + 1), n - k - 2);
    printf("\n");

    print_bin(s, 1);
    print_bin(m, k);
    print_bin(c, n - k - 1);
    printf("\n");
    return 0;
}
