// To insert at the front, at the rear and at a position
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int item){
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->next = NULL;
       
    return new_node;
    
}

NODE insertFront(NODE head, int item){
    NODE new_node = createNode(item);
    if(head == NULL){
        head = new_node;
    } else{
        new_node->next = head;
        head = new_node;
    }
    return head;
}

NODE insertRear(NODE head, int item){
    NODE new_node = createNode(item);
    if(head == NULL){
        return new_node;
    } else {
        NODE temp;
        temp =  head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

NODE insertPosition(NODE head, int item, int position){
    NODE new_node = createNode(item);
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(position == 1){
        new_node->next = head;
        head = new_node;
    } 
    
    NODE prev = NULL;
    NODE cur = head;
    int count = 1;

    while(cur != NULL && count < position){
        prev = cur;
        cur = cur->next;
        count++;
    }

    if(count == position){
        prev->next = new_node;
        new_node->next = cur;
    } else{
        printf("Invalid Postion.\n");
    }

    return head;
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
    NODE head = NULL;
    // let us create a initial linkedlist
    head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(6);
    head->next->next->next->next = createNode(7);
    printf("\nThe initial Linked List: \n");
    display(head); // 2 -> 3 -> 5 -> 6 -> 8 -> NULL

    // let us make the linkedlist 1-> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
    head = insertFront(head,1);
    printf("The Linked List after inserting at Front: \n");
    display(head);
    head = insertPosition(head,4,4);
    printf("The Linked List after inserting at Position 4: \n");
    display(head);
    head = insertRear(head,8);
    printf("The Linked List after inserting at Rear: \n");
    display(head);
    printf("\n");

    return 0;
}