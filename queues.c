#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

struct queue {
    int arr[MAX_SIZE];
    int top;
};

struct queue* init_q(int n) {
    struct queue* newQ = malloc(sizeof(struct queue));
    newQ->arr[0] = n;
    newQ->top = 0;
    return newQ;
}

void push_to_q(struct queue *q, int n) {
    if(q->top >= MAX_SIZE - 1) {
        printf("queue overflow\n");
        return;
    }
    if(q == NULL) return;

    q->arr[++(q->top)] = n;
}


int pop_q(struct queue* q) {
    if(q->top < 0) {
        printf("empty list\n");
        return 0;
    }
    if(q == NULL) return 0;

    int temp = q->arr[0];
    for(int i = 0; i < q->top; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->arr[q->top--] = 0;
    return temp;

}


void print_q(struct queue* q) {
    if(q->top < 0 || q == NULL) return;

    for(int i = 0; i < q->top + 1; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue* fila = init_q(2);

    for(int i = 0; i < 10; i++) {
        push_to_q(fila, (i + 2)*2);
    }
    printf("Queue\n");
    print_q(fila);

    printf("\nPop 4 elements\n");
    for(int i = 0; i < 4; i++) {
        printf("%d ", pop_q(fila));
    }
    printf("\n\n");

    printf("Queue after 4 pops\n");
    print_q(fila);

    return 0;
}
