// to delete a node at front, at rear and at a position
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE deleteFront(NODE head){
    if(head == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    NODE temp = head;
    head = head->rlink;
    head->llink = NULL;
    
    free(temp);

    return head;
}

NODE deleteRear(NODE head){
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if(head->rlink == NULL){
        free(head);
        return NULL;
    }
    NODE temp = head;
    while(temp->rlink->rlink != NULL){
        temp = temp->rlink;
    }
    free(temp->rlink);
    temp->rlink = NULL;

    return head;
}

NODE deletePosition(NODE head, int position){
    if(head == NULL){
        printf("List is empty.\n");
        return NULL;
    }

    if(position == 1){
        NODE temp = head;
        head = head->rlink;
        head->llink = NULL;
        free(temp);
        return head;
    }

    NODE prev = NULL;
    NODE cur = head;
    int count = 1;
    while(cur != NULL && count < position){
        prev = cur;
        cur = cur->rlink;
        count++;
    }
    if(cur != NULL && count==position){
        prev->rlink = cur->rlink;
        if (cur->rlink != NULL) {
            cur->rlink->llink = prev;
        }
        free(cur);
    } else {
        printf("Invalid Position.\n");
    }
    return head;
}

NODE createNode(int item){
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->llink = NULL;
    new_node->rlink = NULL;
    return new_node;
}

void display(NODE head){
    NODE temp = head;
    printf("NULL <-> ");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->rlink;
    }
    printf("NULL\n");
}

int main(){
     NODE head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        NODE new_node = createNode(data);

        if (head == NULL) {
            head = new_node;
        } else {
            NODE temp = head;
            while (temp->rlink != NULL) {
                temp = temp->rlink;
            }
            temp->rlink = new_node;
            new_node->llink = temp;
        }
    }

    int a;
    printf("Choose:\n");
    printf("1.Delete at front\n2. Delete at rear\n3. Delete at position\n");
    scanf("%d",&a);
    int pos;
    switch(a){
        case 1: 
            head =deleteFront(head);
            printf("DLL after deleting at front:\n");
            display(head);
            break;
        case 2: 
            head =deleteRear(head);
            printf("DLL after deleting at rear:\n");
            display(head);
            break;
        case 3: 
            printf("Enter position value: ");
            scanf("%d", &pos);
            head = deletePosition(head,pos);
            printf("DLL after deleting at the position %d: \n",pos);
            display(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
 
    return 0;
}
