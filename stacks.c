#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int* arr;
    int* top;
} stack;

stack* createStack() {
    stack* newStack = (stack*)malloc(sizeof(stack));
    newStack->arr = malloc(sizeof(int) * MAX_SIZE);
    *(newStack->top) = -1;
    return newStack;
}

void pushToStack(stack* stack, int elem) {
    if(*(stack->top) >= MAX_SIZE || *(stack->top) < -1 || stack == NULL || stack->arr == NULL) 
        return;

    *(stack->top) = *(stack->top) + 1;
    *(stack->arr + *(stack->top)) = elem; 
}

int popStack(stack* stack) {
    if(stack == NULL || stack->arr == NULL)
        return 0;
    int temp = *(stack->arr + *(stack->top));
    *(stack->arr + *(stack->top)) = 0;
    *(stack->top) = *(stack->top) - 1;
    return temp;   
}

void printStack(stack* stack) {
    if(stack == NULL || stack->arr == NULL)
        return;
    for(int i = 0; i < *(stack->top) + 1; i++) {
        printf("%d ", *(stack->arr + i));
    }
    printf("\n");
}

int main() {
    stack* stack_1 = createStack();
   
    for(int i = 0; i < 20; i++) {
        pushToStack(stack_1, i*2);
    }

    printStack(stack_1);
    for(int i = 0; i < 10; i++) {
        printf("%d ", popStack(stack_1));
    }
    printf("\n");
    printStack(stack_1);



    return 0;
}
