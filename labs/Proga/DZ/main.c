#include <stdio.h>
#include <stdlib.h>

int maxItemLen(int *arr, int n) {
    int maxItem = arr[0];
    for(int i = 0; i < n - 1; i++){
        if (maxItem < arr[i+1]) maxItem = arr[i+1];
    }
    // printf("%d\n", maxItem);

    int maxItemLen = 0;

    while (maxItem != 0) {
        maxItem /= 10;
        maxItemLen++;
    }
    return maxItemLen;
}

int* radixSort(int *arr, int n, int maxItemLen) {
    int *sortedArr = (int)malloc(sizeof(int) * n);

    

    return sortedArr;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d", maxItemLen(arr, n));

    radixSort(arr, n, maxItemLen(arr, n));

    return 0;
}