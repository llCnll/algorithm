#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000000

// 0代表质数, 1代表合数
int prime[MAX];

int countPrimes(int n){
    memset(prime, 0, sizeof(int)*n);

    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (prime[i] == 0) {
            for (int k = 2; i*k < n; ++k) {
                prime[i*k] = 1;
            }
        }
    }

    for(int i = 2; i < n; ++i) {
        if (prime[i] == 0) {
            count ++;
        }
    }

    return count;
}

int main() {

    printf("%d\n", countPrimes(0));
    printf("%d\n", countPrimes(1));
    printf("%d\n", countPrimes(10));
    printf("%d\n", countPrimes(100));

    return 0;
}
