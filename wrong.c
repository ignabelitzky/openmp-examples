#include <stdio.h>
#include <omp.h>

void wrong() {
    int tmp = 0;
#pragma omp parallel for private(tmp)
    for(int j = 0; j < 1000; ++j) {
        tmp += j;
    }
    printf("%d\n", tmp);
}

int main() {
    wrong();
    return 0;
}
