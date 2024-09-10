// To delete at front, at rear and at a given position
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE deleteFront(NODE head){
    if(head == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    NODE temp = head;
    head = head->next;
    free(temp);

    return head;
}

NODE deleteRear(NODE head){
    if(head == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    NODE temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    return head;
}

NODE deletePosition(NODE head, int position){
    if(head == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    if(position == 1){
        NODE temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    NODE prev = NULL;
    NODE cur = head;
    int count = 1;

    while(cur != NULL && count < position){
        prev = cur;
        cur = cur->next;
        count++;
    }
     if(cur != NULL && count==position){
        prev->next = cur->next;
        free(cur);
    } else{
        printf("Invalid Postion.\n");
    }
    return head;
}

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
    // Lets create the LL: 11 -> 1 -> 2 -> 69 -> 3 -> 4 -> 5 -> NULL
    NODE head = createNode(11);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(69);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("\nInitial Linked List: \n");
    display(head);

    head = deleteFront(head);
    printf("Linked List after deleting from Front: \n");
    display(head);

    head = deleteRear(head);
    printf("Linked List after deleting from Rear: \n");
    display(head);

    head = deletePosition(head,3);
    printf("Linked List after deleting from Position 3: \n");
    display(head);
    printf("\n");

    return 0;
}