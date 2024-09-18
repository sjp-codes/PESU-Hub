// to insert at front, at rear and at a position
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

NODE insertFront(NODE head, int item){
    NODE new_node = createNode(item);
    if(head==NULL){
        head = new_node;
    } else {
        new_node->rlink = head;
        head->llink = new_node;
        head = new_node;
    }

    return head;
}

NODE insertRear(NODE head, int item){
    NODE new_node = createNode(item);
    if(head == NULL){
        head = new_node;
    } else {
        NODE temp = head;
        while(temp-> rlink != NULL){
            temp = temp->rlink;
        }
        temp->rlink = new_node;
        new_node->llink = temp;
    }
    return head;
}

NODE insertPosition(NODE head, int item, int position){
    NODE new_node = createNode(item);
    
    if(position == 1){
        new_node->rlink = head;
        if(head != NULL) {
            head->llink = new_node;  
        }
        head = new_node;
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
    if(count == position){
        prev->rlink = new_node;
        new_node->llink = prev;
        if(cur != NULL) {
            new_node->rlink = cur;
            cur->llink=new_node;
            }
    } else {
        printf("Invalid Position.");
    }

    return head;
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
    printf("Doubly Linked List: \n");
    display(head); // NULL<-> 2 <-> 3 <-> 5 <-> 6 <-> NULL
    head = insertFront(head,1);
    printf("DLL after inserting at front:\n");
    display(head);
    head = insertRear(head,7); 
    printf("DLL after inserting at rear: \n");
    display(head);
    head = insertPosition(head,4,4); 
    printf("DLL after inserting at position: \n");
    display(head);

    // int a;
    // printf("Choose\n");
    // printf("1.Insert at front\n2. Insert at rear\n3. Insert at position\n");
    // scanf("%d",&a);
    // int data, pos;
    // switch(a){
    //     case 1: 
    //         printf("Enter value: ");
    //         scanf("%d", &data);
    //         head = insertFront(head,data);
    //         printf("DLL after inserting at front:\n");
    //         display(head);
    //         break;
    //     case 2: 
    //         printf("Enter value: ");
    //         scanf("%d", &data);
    //         head = insertRear(head,data);
    //         printf("DLL after inserting at rear:\n");
    //         display(head);
    //         break;
    //     case 3: 
    //         printf("Enter value: ");
    //         scanf("%d", &data);
    //         printf("Enter position value: ");
    //         scanf("%d", &pos);
    //         head = insertPosition(head,data,pos);
    //         printf("DLL after inserting at the position %d: \n",pos);
    //         display(head);
    //         break;
    //      default:
    //         printf("Invalid choice\n");
    //         break;
    // }
 
    return 0;
}