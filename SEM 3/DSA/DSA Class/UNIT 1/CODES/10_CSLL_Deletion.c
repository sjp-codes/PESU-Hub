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

NODE deleteFront(){

}

NODE deleteRear(){

}

NODE deletePosition(){
    
}

void display(NODE head){

}

int main(){

    return 0;
}