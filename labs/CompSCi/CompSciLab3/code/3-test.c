#include <stdio.h>
#include <string.h>

char* toAny(char x, int k, int m){
  int length = strlen(x); //длина строки
  int i = 0;
  char intPart[16];
  do{
    intPart[i] = 
    i++;
  }while(i < length && intPart[i] != ".");
}

int main() {
    char x[3];
    int k, m;

    printf("Введите число x, основание его системы счисления k и основание системы счисления m в которую хотите перевести: ");
    scanf("%s %d %d", &x, &k, &m);

    if (k < 2 || k > 10 || m < 2 || m > 10) {
        printf("Мы не умеем работать с системами счисления меньше 2 и больше 10\n");
        return -1;
    }

    printf("Число %s в системе счисления с основанием %d переведенное в систему счисления с основанием %d: %s\n", x, k, m, toAny(x, k, m));
    return 0;
}