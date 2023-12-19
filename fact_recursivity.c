#include <stdio.h>
#include <stdlib.h>

int fibo(int n, int *j) {
    *j = (*j) + 1;
    if(n <= 1) {
        return 1;
    }
    return fibo(n - 1, j) + fibo(n - 2, j);
}

void fiboabstract(int n, int *j) {
    *j = 0;
    int temp = fibo(n, j);
    printf("the %dth position of fibonacci is %d, %d calls\n", n, temp, *j);
    return;

}

int main() {
    int *j;

    //fiboabstract(6, j);
    
    for(int i = 0; i < 20; i++) {
        fiboabstract(i, j);
    }

    return 0;
}
