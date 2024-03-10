#include <stdio.h>
#include <omp.h>

static long long num_steps = 10000000000;
double step;

int main() {
    omp_set_num_threads(8);
    printf("Num of threads: %d\n", omp_get_max_threads());
    long long int i;
    double x, pi, sum = 0.0;
    double start_time, run_time;
    step = 1.0/(double) num_steps;
    start_time = omp_get_wtime();
    #pragma omp parallel for private(x) reduction(+:sum)
    for(i = 1; i <= num_steps; i++) {
        x = (i-0.5) * step;
        sum = sum +4.0/(1.0+x*x);
    }
    pi = step * sum;
    run_time = omp_get_wtime() - start_time;
    printf("PI with %ld steps is %lf in %lf seconds\n", num_steps, pi, run_time);
    return 0;
}
