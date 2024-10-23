#include <stdio.h>
#define SIZE 1024

int n;

// Функция для нахождения обратного по модулю числа https://ru.algorithmica.org/cs/modular/reciprocal/
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    // Используя расширенный алгоритм Евклида
    while (a > 1) {
        q = a / m;
        t = m;
        
        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;

    return x1;
}

// Функция для преобразования числа из СОК в десятичную СС (ост, базисы)
int residueToDec(int residues[], int moduli[]){
    int M = 1; // Произведение базисов
    int X = 0; // Число в 10СС

    // Вычисление произведения базисов
    for (int i = 0; i < n; i++) {
        M *= moduli[i];
    }

    // Число в 10СС
    for (int i = 0; i < n; i++) {
        int Mi = M / moduli[i]; // Частичное произведение
        int yi = modInverse(Mi, moduli[i]); // Обратное по модулю число
        X += residues[i] * Mi * yi;
    }

    return X % M; // Результат по модулю M
}

// Функция для сложения чисел в системе остаточных классов (базисы, ост1, ост2)
int calcSum(int moduliArr[], int residues1Arr[], int residues2Arr[]){
    int residueSum[SIZE];

    for (int i = 0; i < n; i++) {
        residueSum[i] = (residues1Arr[i] + residues2Arr[i]) % moduliArr[i];
    }

    return residueToDec(residueSum, moduliArr);
}

// Функция для записи чисел в массивы (массив)
int writeToArr(int arr[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}
/*
int printArr(int arr[]){

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf(" ");
}
*/
int main() {
    scanf("%d", &n);

    int moduli[SIZE];
    int residues0[SIZE];
    int residues1[SIZE];

    writeToArr(moduli);
    writeToArr(residues0);
    writeToArr(residues1);

    int resVal = calcSum(moduli, residues0, residues1);
    if (resVal == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", resVal);
    }
    return 0;
}