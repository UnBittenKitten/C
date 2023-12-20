#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//didnt finish some functions, but shouldnt take much time

#define MAXSIZE 5


typedef struct {
    int* arr;
    int elemNum;
    int maxSize;
} dynArray;

void arrayInit(dynArray** arr_ptr) {
    dynArray *container;
    container = (dynArray*)malloc(sizeof(dynArray));
    if(!container) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    container->elemNum = 0;
    container->maxSize = MAXSIZE;
    container->arr = (int *)malloc(MAXSIZE * sizeof(int));

    if (!container->arr){ 
        printf("Memory Allocation Failed\n"); 
        exit(0); 
    } 
    *arr_ptr = container;

}

void addToDynArray(dynArray* new_arr, int data) {
    if(new_arr->elemNum >= new_arr->maxSize - 1) {
        new_arr->maxSize <<= 1;
        new_arr->arr = realloc(new_arr->arr, (new_arr->maxSize) * sizeof(int));
    }
    new_arr->arr[new_arr->elemNum] = data;
    new_arr->elemNum += 1;
}

void printDynArr(dynArray* dyn_arr) {
    if(!dyn_arr->arr) {
        printf("NULL pointer");
    }
    for(int i = 0; i < dyn_arr->elemNum; i++) {
        printf("%d ", dyn_arr->arr[i]);
    }

}

void delete_n(dynArray* dyn_arr, int n) {

}

int read_n(dynArray* dyn_arr, int n) {

}

void free_dyn_arr(dynArray** dyn_arr) {
    
}

int main() {
    clock_t begin = clock();
    int n = 100000;
    
    dynArray* arr_2;
    arrayInit(&arr_2);

    for(int i = 0; i < n; i++) {
        addToDynArray(arr_2, i + 10);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime spent = %lf", time_spent);
    printf("\n");


    for(int i = 0; i < 10; i++) {
        printf("%d ", arr_2->arr[i]);
    }
    printf("\n");

    for(int i = 0; i < 10; i++) {
        printf("%d ", arr_2->arr[arr_2->elemNum - i - 1]);
    }
    printf("\n");

    
    return 0;
}
