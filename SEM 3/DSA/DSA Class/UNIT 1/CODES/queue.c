// #define MAXQUEUE 10

// struct queue{
//     int items[MAXQUEUE];
//     int front,rear;
// };

// struct queue q;
// q.front=q.rear=-1;

// void insert(int x, struct queue *q){
//     if(q->rear==MAXQUEUE-1){
//         printf("full queue");
//         return;
//     }
//     if(q->front == -1 && q->rear == -1){
//         q->front++;
//         q->rear++;
//         q->items[q->rear]=x;
//         return;
//     }
//     q->rear++;
//     q->items[q->rear]=x;
// }

// int remove(struct queue *q){
//     int x;
//     if(q->front==-1){
//         printf("empty");
//         return;
//     }
//     x=q->items[q->front];
//     if(q->front==q->rear){
//         q->front=q->rear=-1;
//     }
//     else{
//         q->front++;
//         return x;
//     }
// }

// struct node{
//     int data;
//     struct node* next;
// };

// struct queue{
//     struct node *front;
//     struct node *rear;
// };

// struct queue q;

// q.rear=q->front=NULL;

// void insert(int x, struct queue *q){
//     p=(struct node*)malloc(sizeof(struct node));
//     p->data=x;
//     p->next=NULL;
//     if(q->rear==NULL && q->front==NULL){
//         q.front=p;
//     } else{
//         next(q->rear)=p;
//     }
//     q.rear=p;
// }

// int remove(struct queue *q){
//     int x;
//     if(q->front == NULL){
//         printf("empty");
//     }
//     else{
//         p=(struct node*)malloc(sizeof(struct node));
//         p=q->front;
//         x=p->data;
//         q->front=q->front->next;
//         if(q->front==NULL){
//             q->rear=NULL;

//         }
//         free(p);
//         return x;
//     }
// }

int survivor(NODE *head, int n){
    struct *p,*q;
    int i;
    q=p=*head;
    while(p->next!=p){
        for(i=0;i<n-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        printf("%d",p->data);
        free(p);
        p=q->next;
    }
    *head=p;
    return(p->data);
}
