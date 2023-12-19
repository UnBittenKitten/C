#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct ends {
    struct node* first_el;
    struct node* last_el;
};

struct ends* create_list(int n) {
    struct ends* newends = malloc(sizeof(struct ends));

    struct node* newList = malloc(sizeof(struct node));
    newList->data = n;
    newList->prev = NULL;
    newList->next = NULL;

    newends->first_el = newList;
    newends->last_el = newList;

    return newends;
}


int num_of_nodes(struct ends* list) {
    if(list == NULL) {
        printf("empty list\n");
        return 0;
    }
    int count = 1;
    struct node* pt = list->first_el;
    while(pt->next != NULL) {
        pt = pt->next;
        count++;
    }
    return count;
}

void add_node(struct ends* list, int n) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = list->last_el;
    list->last_el = newNode;
    list->last_el->prev->next = newNode;
}

void print_list(struct ends* list) {
    if(list == NULL) {
        printf("empty list\n");
        return;
    }

    struct node* ptr = list->first_el;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverse_print_list(struct ends* list) {
    if(list == NULL) {
        printf("empty list\n");
        return;
    }
    struct node* ptr = list->last_el;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main() {
    struct ends* list = create_list(0);  

    for(int i = 1; i < 20; i++) {
        add_node(list, i);
    }

    printf("normal print  = ");
    print_list(list);
    printf("reverse print = ");
    reverse_print_list(list);

    printf("num of nodes  = %d\n", num_of_nodes(list));


    return 0;
}
