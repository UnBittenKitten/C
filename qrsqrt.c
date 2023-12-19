#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define millions 1000

float q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*) &i;
    y = y *(threehalfs - (x2 * y * y));
    return y;
}

int main() {
    float *arr = malloc(millions * sizeof(float*));
    float *arr2 = malloc(millions * sizeof(float*));

    printf("number of elements = %d\n", millions);

    clock_t begin = clock();
    for(int i = 0; i < millions; i++) {
        *(arr + i) = 1 / pow(i, 0.5);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("normal operation   ");
    for(int i = 0; i < 5; i++) {
        printf("%f ", *(arr + i + 1));
    }
    printf("   time spent = %lf\n", time_spent);

    //printf("\ntest = %f\n", q_rsqrt(4));

    begin = clock();
    for(int i = 0; i < millions; i++) {
        *(arr2 + i) = q_rsqrt(i);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("q_rsqrt            ");
    for(int i = 0; i < 5; i++) {
        printf("%f ", *(arr2 + i + 1));
    }
    printf("   time spent = %lf\n", time_spent);



    return 0;
}
