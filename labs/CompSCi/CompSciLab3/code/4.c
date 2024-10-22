#include <stdio.h>
#define SIZE 1024

int n;

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    // Apply extended Euclidean algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
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

int residueToDec(int residues[], int moduli[]){
    int M = 1; // Product of moduli
    int X = 0; // Resulting decimal value

    // Step 1: Calculate the product of moduli
    for (int i = 0; i < n; i++) {
        M *= moduli[i];
    }

    // Step 2: Calculate the decimal value
    for (int i = 0; i < n; i++) {
        int Mi = M / moduli[i]; // Partial product
        int yi = modInverse(Mi, moduli[i]); // Modular inverse
        X += residues[i] * Mi * yi; // Combine the results
    }

    return X % M; // Return the result modulo M
}

int calcSum(int moduli[], int residues0[], int residues1[]){
    int residueSum[SIZE];

    for (int i = 0; i < n; i++) {
        residueSum[i] = (residues0[i] + residues1[i]) % moduli[i];
    }

    return residueToDec(residueSum, moduli);
}

int writeToArr(int arr[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

int printArr(int arr[]){

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf(" ");
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
    if (resVal == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", resVal);
    }
    return 0;
}