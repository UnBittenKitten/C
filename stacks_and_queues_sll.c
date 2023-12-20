#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct tails {
    struct node* head;
    struct node* last;
};

struct tails* init_list(int n) {
    struct tails* newList = malloc(sizeof(struct tails));
    struct node* Nnode = malloc(sizeof(struct node));
    Nnode->data = n;
    Nnode->link = NULL;
    newList->head = Nnode;
    newList->last = Nnode;
    return newList;
}

void print_list(struct tails* list) {
    if(list == NULL || list->head == NULL) return;
    struct node* ptr = list->head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


void push_to(struct tails* list, int nData) {
    if(list == NULL || list->head == NULL) return;
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = nData;
    newNode->link = NULL;

    list->last->link = newNode;
    list->last = newNode;
}

int queue_pop(struct tails* list) {
    if(list == NULL || list->head == NULL) return 0;
    int temp = list->head->data;
    struct node* list_temp = list->head;

    list->head = list->head->link;
    free(list_temp);
    return temp;
}

int stack_pop(struct tails* list) {
    if(list == NULL || list->head == NULL) return 0;
    struct node* ptr = list->head;
    while(ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    int temp = ptr->link->data;
    struct node* tempNode = ptr->link;
    ptr->link = NULL;
    free(tempNode);
    return temp;
}

void delete_list(struct tails* list) {
    if(list == NULL || list->head == NULL) return;
    struct node* ptr = list->head;
    while(ptr != NULL) {
        ptr = ptr->link;
        free(list->head);
        list->head = ptr;
    }
    list->head = NULL;
    list->last = NULL;
}

int main() {

    struct tails* sllist_1 = init_list(0);

    for(int i = 1; i < 21; i++) {
        push_to(sllist_1, i*2);
    }
    printf("linked list =   ");
    print_list(sllist_1);

    printf("queue_pop(5) =  ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", queue_pop(sllist_1));
    }
    printf("\n");
    printf("linked list =   ");
    print_list(sllist_1);


    printf("stack_pop(5) =  ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", stack_pop(sllist_1));
    }
    printf("\n");
    printf("linked list =   ");
    print_list(sllist_1);

    delete_list(sllist_1);
    print_list(sllist_1);

    return 0;
}
