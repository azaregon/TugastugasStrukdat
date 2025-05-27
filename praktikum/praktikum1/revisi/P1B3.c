
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;


/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int queue_front(Queue *queue);
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

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
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

int queue_front(Queue *queue)
{

    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
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
    Queue q;
    queue_init(&q);

    int ToAn,ByBr,AnKm;
    scanf("%d %d %d",&ToAn,&ByBr,&AnKm);
    
    
    for (int i = 0; i < ToAn; i++) {
        int inginBr;
        
        scanf("%d", &inginBr);
        
        queue_push(&q,inginBr);

        
    }
    // node * now = &q->head;
    // for (int i = 0; i < &q->size; i++) {
        //     printf("[%d %d] -> ",now->data,now->isMe);
        //     now = now->next;
        // }
        
        
    int iter = 0;
    int ToAnKm = 0;

    // while (ByBr > 0 )  {
    while (!queue_isEmpty(&q) && ByBr > 0)  {
        // if (ByBr <= 0) {
        //     break;
        // }
        iter++;
        // printf("%d\n", iter);
        
        int now = queue_front(&q);
        queue_pop(&q);
        
        if (iter % AnKm != 0) {
            // if (now.isMe == 1) {
                //     // ToAnKm = 0;
                //     if (ByBr > now.data){
                    //         printf("%d Yes Dapat burger gratis!!!",ToAnKm); 
                    //         return 1;
                    //     }
                    // }
                    
            ByBr -= now;
                    
        } else {

            queue_push(&q,now); 
            ToAnKm ++;
            
        }
        
    }

    printf("%d ",ToAnKm);
    if (ByBr > 0){

        printf("Yes Dapat burger gratis!!!"); 
    } else {
        printf("NOO tidak Dapat :(");
    }


} 