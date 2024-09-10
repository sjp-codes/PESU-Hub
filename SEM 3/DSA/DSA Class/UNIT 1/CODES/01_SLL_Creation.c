// To create a node 
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node* NODE;

NODE createNode(int item){
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->next = NULL;
       
     return new_node;
    
}

void display(NODE head){
    NODE temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int a,b,c;
    NODE head = NULL;
    printf("Enter first data value: ");
    scanf("%d",&a);
    printf("Enter second data value: ");
    scanf("%d",&b);
    printf("Enter third data value: ");
    scanf("%d",&c);
    head = createNode(a);
    head->next = createNode(b);
    head->next->next = createNode(c);
    printf("Data at first/head node: %d\n",head->data);
    printf("Data at second node: %d\n",head->next->data);
    printf("Data at third node: %d\n",head->next->next->data);
    printf("LinkedList: ");
    display(head);
    return 0;
}