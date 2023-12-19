#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

//just a way of creating a matrix only with pointers

int main() {
    int** arr = (int**)malloc(MAX_SIZE * sizeof(int*));

    for(int i = 0; i < MAX_SIZE; i++) {
        *(arr + i) = malloc(MAX_SIZE * sizeof(int));
    }

    for(int i = 0; i < MAX_SIZE; i++) {
        **(arr + i) = i + 1;
    }
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            *(*(arr + i) + j) = (j + 1) * (i + 1);
        }
    }

    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}