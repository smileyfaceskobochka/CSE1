#include <stdio.h>

int toAny(float x, int k, int m){
    int intPartX = (int)x;
    int intPartRes[64];
    int i = 0;
    do {
        intPartRes[i] = intPartX % 10;
        intPartX /= 10;
        i++;
    } while (intPartX > 0);
    printf("%d", intPartRes); //Вывод i
}

int main() {
    float x;
    int k, m;

    printf("Введите число x, основание его системы счисления k и основание системы счисления в которую хотите перевести: ");
    scanf("%f %d %d", &x, &k, &m);

    if (k < 2 || k > 10 || m < 2 || m > 10) {
        printf("Мы не умеем работать с системами счисления меньше 2 и больше 10\n");
        return -1;
    }

    printf("Число %f в системе счисления с основанием %d переведенное в систему счисления с основанием %d: %s\n", x, k, m, toAny(x, k, m));
    return 0;
}