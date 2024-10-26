#include <stdio.h>
#define SIZE 1024

int n;

// Функция для нахождения обратного по модулю числа (Разобраться в алгоритме)
int modMultInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // 
    if (x < 0)
        x += m0;

    return x;
}

// Функция для преобразования числа из СОК в десятичную СС (ост, базисы) https://www.ispras.ru/proceedings/docs/2024/36/4/isp_36_2024_4_117.pdf
int residueToDec(int residues[], int moduli[]){
    int prod = 1; // Произведение модулей
    int res = 0;  // Результат в десятичной системе

    // Вычисление произведения модулей
    for (int i = 0; i < n; i++) {
        prod *= moduli[i];
    }

    // Вычисление результата в десятичной системе
    for (int i = 0; i < n; i++) {
        int partProd = prod / moduli[i]; // Частичное произведение
        int inv = modMultInverse(partProd, moduli[i]); // Обратное по модулю число
        res += residues[i] * partProd * inv;
    }

    return res % prod; // Результат по модулю product
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

int exitWithErr(int moduli[], int residues0[], int residues1[]) {
    int range = 1; // находим диапазон +1
    for (int i = 0; i < n; i++) {
        range *= moduli[i];
    }
    
    // Преобразуем остатки в десятичное число
    int decimalValue0 = residueToDec(residues0, moduli);
    int decimalValue1 = residueToDec(residues1, moduli);

    int totValue = decimalValue0 + decimalValue1;
    if (totValue < 0 || totValue >= range) {
        return -1; // Если сумма выходит за пределы диапазона, возвращаем -1
    }

    return 0;
}

int main() {
    scanf("%d", &n);

    int moduli[SIZE];
    int residues0[SIZE];
    int residues1[SIZE];

    writeToArr(moduli);
    writeToArr(residues0);
    writeToArr(residues1);

    int resVal = calcSum(moduli, residues0, residues1);
    if (exitWithErr(moduli, residues0, residues1) == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", resVal);
    }
    return 0;
}