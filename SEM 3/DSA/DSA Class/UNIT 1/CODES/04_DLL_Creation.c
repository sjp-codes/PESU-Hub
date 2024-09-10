#include <stdio.h>
#include <stdlib.h>

// llink-data-rlink
struct node{
    int data;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE createNode(int item){
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->llink = NULL;
    new_node->rlink = NULL;
    return new_node;
}

// Display in forward direction
void display(NODE head){
    NODE temp = head;
    printf("NULL <-> ");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->rlink;
    }
    printf("NULL\n");
}

//Display in backward direction
void displayBW(NODE tail){
    NODE temp = tail;
    printf("NULL <-> ");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->llink;
    }
    printf("NULL\n");
}

int main(){
     NODE head = NULL, tail = NULL; 
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        NODE new_node = createNode(data);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->rlink = new_node;
            new_node->llink = tail;
            tail = new_node;  
        }
    }

    printf("Doubly Linked List (Forward):\n");
    display(head);

    printf("Doubly Linked List (Backward):\n");
    displayBW(tail);

    return 0;
}