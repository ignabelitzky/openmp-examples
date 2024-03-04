#include <stdio.h>
#include <omp.h>

#define MAX 100

int main() {
    int A[MAX];
    int incr = 0;
#pragma omp parallel for firstprivate(incr)
    for(int i = 0; i < MAX; ++i) {
        if((i % 2) == 0)
            incr++;
        A[i] = incr;
    }
    for(int i = 0; i < MAX; ++i) {
        printf("%d\n", A[i]);
    }
    return 0;
} 
