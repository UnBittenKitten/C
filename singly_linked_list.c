#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};

struct node* create_list() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->link = NULL;
    return head;
}

int count_of_nodes(struct node *nHead) {
    int count = 0;
    if(nHead == NULL) {
        printf("Linked list is empty\n");
    }
    struct node *ptr = NULL;
    ptr = nHead;
    while(ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    return count;
}

void print_data(struct node * nHead) {
    if(nHead == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *ptr = NULL;
    ptr = nHead;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void add_data(int nData, struct node *nHead) {//reduce innecesary variables
    if(nHead == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *ptr, *temp;
    ptr = nHead;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = nData;
    temp->link = NULL;

    while(ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
    
}

struct node* insert_at_end_optimal(int nData, struct node* EOL) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = nData;
    temp->link = NULL;

    EOL->link = temp;
    return temp;
}

void insert_at_n(int nData, int pos, struct node **nHead) {
    if(*nHead == NULL) {
        printf("Empty List\n");
    }
    if(pos <= 0) {
        printf("unsupported position\n");
        return;
    }
    if(pos > count_of_nodes(*nHead)) {
        printf("\nOUT OF SCOPE\n");
        return;
    }

    int count = 1;
    struct node *ptr = *nHead;

    while(count < pos  - 1) {
        ptr = ptr->link;
        count = count + 1;
    }

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = nData;
    newNode->link = ptr->link;
    ptr->link = newNode;

}

void insert_at_start(int nData, struct node **nHead) {
    if(nHead == NULL) {
        printf("Empty list\n");
        return;
    }

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = nData;
    newNode->link = *nHead; //sets the link of newNode to the address of the head

    *nHead = newNode; //sets the struct that head points to, to newNode (newNode is a struct)
}

void delete_start(struct node **nHead) { //test if it actually frees the memory, im too tired for this
    if(nHead == NULL) {
        printf("Empty list\n");
        return;
    }
    void *temp = *nHead;
    *nHead = (*nHead)->link;
    free(temp);
}

void delete_end(struct node *nHead) {
    if(nHead->link == NULL) {
        printf("there is no last element");
    }
    struct node* ptr;
    struct node* temp;
    ptr = nHead;
    while(ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    temp = ptr->link;
    ptr->link = NULL;
    free(temp);
    
}

int read_n(int n, struct node* nHead) {
    if(nHead == NULL) {
        printf("Empty list\n");
        return 0;
    }

    struct node* ptr = nHead;
    int count = 0;
    while(count < n - 1) {
        ptr = ptr->link;
        count++;
    }
    return ptr->data;
}

void delete_n(int n, struct node *nHead) {
    if(nHead == NULL) {
        printf("Empty list\n");
        return;
    }
    int count = 1;
    struct node *ptr = nHead;

    while(count < n - 1) {
        //printf("count = %d\n", count);
        ptr = ptr->link;
        count = count + 1;
    }

    struct node *temp = ptr->link->link;
    ptr->link = temp;
}

int search_list(int nData, struct node *nHead) { //returns the position of the queried element
    if(nHead == NULL) {
        printf("Empty list\n");
        return 0;
    }
    struct node* ptr = nHead;
    for(int i = 1; i <= count_of_nodes(nHead); i++) {
        if(ptr->data == nData) {
            return i;
        }
        ptr = ptr->link;
    }
    return -1;
}

void delete_whole_list(struct node** nHead) {
    struct node *temp = *nHead;
    while(temp != NULL) {
        temp = temp->link;
        free(*nHead);
        *nHead = temp;
    }
}

int main() {

    struct node* head = create_list();
    struct node *EOL = head; //(End Of List)

    for(int i = 1; i < 12; i++) {
        //add_data(i, head);
        EOL = insert_at_end_optimal(i, EOL); //optimal function, but worse redability. O(1)
    }

    printf("Data: \n");
    print_data(head);
    printf("Count of nodes = %d\n\n", count_of_nodes(head));



    printf("delete_start (2): \n");
    delete_start(&head);
    delete_start(&head);
    printf("Data: \n");
    print_data(head);
    printf("Count of nodes = %d\n\n", count_of_nodes(head));


    printf("Insert 21 at 3:\n");
    insert_at_n(21, 4, &head); //bugged
    //delete_n(7, head);
    printf("Data: \n");
    print_data(head);
    printf("Count of nodes = %d\n\n", count_of_nodes(head));


    printf("delete at 2:\n");
    delete_n(2, head);
    //delete_n(2, head);
    //delete_n(3, head);
    //delete_n(2, head);

    printf("Data: \n");
    print_data(head);
    printf("Count of nodes = %d\n\n", count_of_nodes(head));

    printf("Read at 4 = %d\n", read_n(4, head));
    printf("Data: \n");
    print_data(head);

    printf("\nDelete End:\n");
    delete_end(head);
    delete_end(head);
    printf("Data:\n");
    print_data(head);

    int query = 8;
    printf("\nSearching the list\nSearching for number %d\n", query);
    printf("The position of %d is %d\n", query, search_list(query, head));

    printf("\nDELETE THE LIST\n\n");
    delete_whole_list(&head);
    print_data(head);
    print_data(head);


    return 0;
}
