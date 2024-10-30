#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    
}