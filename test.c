#include <stdio.h>
#include <omp.h>

int isPrime(int n) {
    for(int i = 2; i <= n/2; i++)
        if(!(n%i))
            return 0;
    return 1;
}

int main() {
    int numPrimes = 0;
#pragma omp parallel for reduction(+:numPrimes)
    for(int i = 2; i < 250001; i++)
        numPrimes += isPrime(i);

    printf("%d\n", numPrimes);
    return 0;
}
