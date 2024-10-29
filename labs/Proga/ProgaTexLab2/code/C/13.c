#include <stdio.h>
#include <stdlib.h>

// int main() {
//     int n;
//     scanf("%d", &n);

//     int *arr = (int*)malloc(sizeof(int) * n);

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     for (int i = 0; i < n; i++) {
//         if (arr[i] == 0) {
//             arr[i] = arr[(i + n - 1) % n] + arr[(i + n - 2) % n];
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     //free(arr);
//     return 0;
// }

// program solution13;

// var N, i:integer;
// var ring, digits: array[1..128] of integer;

// begin
//     readln(N);

//     for i := 1 to N do
//         read(ring[i]);

//     for i := 1 to N do
//     begin
//         if ring[i] = 0 then
//         begin
//             if i = 1 then
//                 digits[i] := ring[N] + ring[N - 1]
//             else if i = 2 then
//                 digits[i] := ring[1] + ring[N]
//             else
//                 digits[i] := ring[i - 1] + ring[i - 2];
//         end
//         else
//             digits[i] := ring[i];
//     end;

//     for i := 1 to N do
//         write(digits[i], ' ');
// end.

int main(){
    int n;
    int *arr, *narr = (int*)malloc(sizeof(int)*n);

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(arr[i]==0){
            if(i == 0){
                narr[i] = arr[n-1] + arr[n-2];
            } else if (i == 1){
                narr[i] = arr[0] + arr[n-1];
            } else narr[i] = arr[i-2] + arr[i-1];
        } else narr[i] = arr[i];
    }

    for(int i = 0; i < n; i++){
        printf("%d ", narr[i]);
    }
    return 0;
}