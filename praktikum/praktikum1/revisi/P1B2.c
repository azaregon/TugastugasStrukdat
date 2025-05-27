// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     struct node * prev;
//     int data;
//     int isMe;
//     struct node * next;
// } node;


// typedef struct LinkedList{
//     node * head;
//     node * tail;
//     unsigned size;
// } LinkedList ;


// LinkedList * initLL() {
//     LinkedList * newLL = malloc(sizeof(LinkedList));
//     newLL->size = 0;
//     return newLL; 
// }

// typedef struct RETDAT {
//     int data;
//     int isMe;
// }  RetDat; 

// ============================================!!=======================

// void pushBack(LinkedList * ll, int data) {
//     node * newNode = malloc(sizeof(node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (ll->size == 0) {
//         newNode->prev = NULL;
//         ll->head = newNode;
//         ll->tail = newNode;

        

//     } else {
//         newNode->prev = ll->tail;
//         ll->tail->next = newNode;
//         ll->tail = newNode;
//     }
//     ll->size++;

// }



// void pushFront(LinkedList * ll, int data,int isMe) {
//     node * newNode = malloc(sizeof(node));
//     newNode->data = data;
//     newNode->isMe = isMe;
//     newNode->prev = NULL;
//     newNode->next = NULL;

//     if (ll->size == 0) {
//         newNode->prev = NULL;
//         ll->head = newNode;
//         ll->tail = newNode;

        

//     } else {
//         newNode->next = ll->head;
//         ll->head->prev = newNode;
//         ll->head = newNode;
//     }
//     ll->size++;

// }


// RetDat popBack(LinkedList *ll) {
//     node * teil = ll->tail;

//     RetDat retVal;
//     retVal.data = teil->data;
//     retVal.isMe = teil->isMe;

//     if (teil == NULL) {
//         return retVal;
//     } else if (ll->size == 1 ||( teil->next == NULL && teil->prev == NULL)) {
//         ll->head = NULL;
//         ll->tail = NULL;
//         ll->size--;

//         return retVal;
//     } else {
//         teil->prev->next = NULL;
//         ll->tail = teil->prev;

//         free(teil);

//         ll->size--;
//         return retVal;

//     }
// }

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    int isMe;
    struct queueNode_t *next;
} QueueNode;

typedef struct retdat {
    int data;
    int isMe;
} RetDat;


/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value,int isMe);
void queue_pop(Queue *queue);
RetDat queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value,int isMe)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->isMe = isMe;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

RetDat queue_front(Queue *queue)
{
    RetDat retVal;
    if (!queue_isEmpty(queue)) {
        retVal.data = queue->_front->data;
        retVal.isMe = queue->_front->isMe;
        return retVal;
        // return (queue->_front->data);
    }
    retVal.data = 0;
    retVal.isMe = 0;
    return retVal;
    // return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}


// void queue_init(Queue *queue);
// bool queue_isEmpty(Queue *queue);
// void queue_push(Queue *queue, int value);
// void queue_pop(Queue *queue);
// int  queue_front(Queue *queue);
// int  queue_size(Queue *queue);


int main() {
    // LinkedList * &q = initLL();
    Queue q;
    queue_init(&q);

    int ToAn,ByBr,AnKm;
    scanf("%d %d %d",&ToAn,&ByBr,&AnKm);
    
    
    for (int i = 0; i < ToAn; i++) {
        int inginBr;
        
        scanf("%d", &inginBr);
        
        if (i == ToAn-1){
            queue_push(&q,inginBr,1);
        } else {
            queue_push(&q,inginBr,0);
        }
        
    }
    // node * now = &q->head;
    // for (int i = 0; i < &q->size; i++) {
        //     printf("[%d %d] -> ",now->data,now->isMe);
        //     now = now->next;
        // }
        
        
    int iter = 0;
    int ToAnKm = 0;

    // while (ByBr > 0 )  {
    while (!queue_isEmpty(&q))  {
        if (ByBr <= 0) {
            break;
        }
        iter++;
        
        if (iter % AnKm != 0) {
            
            RetDat now = queue_front(&q);
            queue_pop(&q);
            if (now.isMe == 1) {
                // ToAnKm = 0;
                if (ByBr > now.data){
                    printf("%d ",ToAnKm);
                    printf("Yes Dapat burger gratis!!!"); 
                    return 1;
                }
            }
            ByBr -= now.data;
            
        } else {
            RetDat now = queue_front(&q);
            queue_pop(&q);
            queue_push(&q,now.data, now.isMe); 
            ToAnKm += 1;
            
        }
        
    }

    printf("%d",ToAnKm);
    printf("NOO tidak Dapat :(");



    // int iteration = 0;
    // while (ByBr > 0 || !queue_isEmpty(&q)) {
    //     iteration++;

    //     // printf("%d    | ",ByBr);
    //     // node * now = &q->head;
    //     // for (int i = 0; i < &q->size; i++) {
    //     //     printf("[%d %d] ->",now->data,now->isMe);
    //     //     now = now->next;
    //     // }
    //     // printf("\n");

    //     RetDat popped = queue_front(&q); 
    //     queue_pop(&q);

        

    //     if (iteration % AnKm == 0 ) {
    //         // pushFront(&q,popped.data,popped.isMe);
    //         queue_push(&q,popped.data,popped.isMe);
    //         ToAnKm++;
    //     } else {
    //         if (popped.isMe == 1 && ByBr > popped.data) {
    //             printf("%d Yes Dapat burger gratis!!!",ToAnKm);
    //             return 1;
    //         }
    //         ByBr -= popped.data;    

    //     }

    //     // printf("\n");
    //     // printf("%d    | ",ByBr);
    //     // QueueNode now = q._front;
    //     // for (int i = 0; i < q._size; i++) {
    //     //     printf("[%d %d] ->",now.data,now.isMe);
    //     //     now = now.next;
    //     // }
    // }


    // printf("%d NOO tidak Dapat :(", ToAnKm);



} 