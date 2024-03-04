#include <stdio.h>
#include <omp.h>

int main() {
    // Variables A = 1, B = 1, C = 1
#pragma omp parallel private(B) firstprivate(C)
    return 0;
}

// Are A, B, C local to each thread or shared inside the parallel region?
// Answer: B is local to each thread initialized to 0, A is shared inside the parallel region
// but C will be private for each thread but with a initial value of 1
//
// What are their initial values inside and values after the parallel region?
// INITIAL
// A = 0, B = UNDEFINED, C = 1
//
// AFTER
// B and C reverto to their original values of 1
// A is either 1 or the value modified inside the parallel region
