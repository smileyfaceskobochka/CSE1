#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Функция для нахождения максимальной длины числа в массиве
int maxItemLen(int *arr, int n) {
    int maxItem = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxItem) maxItem = arr[i];
    }

    int maxItemLen = 0;
    while (maxItem != 0) {
        maxItem /= 10;
        maxItemLen++;
    }
    return maxItemLen;
}

// Функция сортировки на основе текущего разряда
void countingSortByDigit(int *arr, int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Подсчет числа элементов для каждой цифры
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Префиксная сумма для правильной позиции
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Сборка отсортированного массива
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Копирование обратно в исходный массив
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Рекурсивная функция сортировки MSD
void radixSortRecursive(int *arr, int n, int maxLen, int currentDigit) {
    if (currentDigit >= maxLen || n <= 1) {
        return; // Базовый случай: достигнут последний разряд или массив уже отсортирован
    }

    countingSortByDigit(arr, n, (int)pow(10, maxLen - currentDigit - 1));

    // Разделяем массив на подмассивы по текущему разряду
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || (arr[i] / (int)pow(10, maxLen - currentDigit - 1)) % 10 != 
                    (arr[start] / (int)pow(10, maxLen - currentDigit - 1)) % 10) {
            // Рекурсивно сортируем подмассив
            radixSortRecursive(arr + start, i - start, maxLen, currentDigit + 1);
            start = i;
        }
    }
}

// Внешняя функция для сортировки
void radixSort(int *arr, int n) {
    int maxLen = maxItemLen(arr, n);
    radixSortRecursive(arr, n, maxLen, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
