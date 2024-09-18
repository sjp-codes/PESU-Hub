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

NODE insertFront(NODE tail, int item){
    NODE new_node = createNode(item);
    if(tail == NULL){
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;

    return tail;
}

NODE insertRear(NODE tail, int item){
    NODE new_node = createNode(item);
    if(tail == NULL){
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
    
    return tail;
}

NODE insertPosition(NODE tail, int item, int position){
    NODE new_node = createNode(item);
    
}

void display(NODE tail){

}

int main(){

    return 0;
}