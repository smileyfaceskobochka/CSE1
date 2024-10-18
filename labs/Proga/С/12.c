#include <stdio.h>

long Perfecto(long n){
    long sum;

    for(long i = 1; i <= n / 2; i++){
        if(n % i == 0){
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    long n;
    scanf("%ld", &n);

    if(Perfecto(n)){
        printf("YES\n");
    } else{
        printf("NO\n");
    }

    return 0;
}