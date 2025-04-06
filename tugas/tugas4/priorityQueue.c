#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    int priority;
} node ;


typedef struct priorityQueue {
    node data[10];
    int head;
    int tail;
    int size;
} PQueue;


PQueue *initQueue() {
    PQueue *newQ = malloc(sizeof(PQueue));

    newQ->head = 0;
    newQ->tail = 0;
    newQ->size = 0;
}

int isEmpty(PQueue *queue) {
    if (queue->size == 0 ) return 1;
    return 0;
}

int isFull(PQueue* queue) {
    if (queue->size == 10 ) return 1;
    return 0;
}

void swapN(node * add1,node * add2) {
    int svDt = add1->data;
    int svPr = add1->priority;
    add1->data = add2->data;
    add1->priority = add2->priority;
    add2->data = svDt;
    add2->priority = svPr;
}




void push(PQueue *queue, int data,int priority) {
    
    if (isEmpty(queue)) {
        printf("a\n");
        queue->data[queue->tail].data =  data;
        queue->data[queue->tail].priority = priority;
        
        queue->size++;
    } else if (!isFull(queue)) {

        queue->tail++;
        queue->data[queue->tail].data =  data;
        queue->data[queue->tail].priority = priority;

        int now = queue->tail;

        while(now >= 1 ) {

            if (queue->data[now].priority < queue->data[now-1].priority) {
                swapN(&queue->data[now], &queue->data[now-1]);
                now-=1;
            }
             else break;




        }

        queue->size++;

    } else {
        printf("cannot push, queue is full\n");
    }

    
}


void shiftArrToLeft(PQueue *queue) {
    for (int i = 0; i < queue->size-1;i++) {
        swapN(&queue->data[i],&queue->data[i+1]);
    }
}

int pop(PQueue *queue) {

    if (isEmpty(queue)) printf("empt\n");

    int retVal = queue->data[queue->head].data;

    shiftArrToLeft(queue);


    queue->size--;
    queue->tail--;
    return retVal;
}

// void removeAtN(PQueue *queue, int nth) {
//     int i = nth;
//     while (i < )
// }

void removeWhere(PQueue *queue,int toRm) {
    int i = 0;
    while (1) {

        if (queue->data[i].data == toRm) {
            int j = i;
            while (j < queue->size-1) {
                swapN(&queue->data[j],&queue->data[j+1]);
                j++;
            }
            queue->size--;
            queue->tail--;
        }
        
        if (i == queue->tail) break;

        i++;
    }
}


int main() {

    PQueue *A = initQueue();
    push(A,1,2);
    push(A,2,3);
    push(A,3,1);
    push(A,4,2);
    push(A,4,1);
    push(A,5,1);
    push(A,6,4);
    push(A,4,3);
    push(A,7,4);
    push(A,8,1);
    push(A,5,3);
    pop(A);
    pop(A);
    pop(A);
    // for (int i = 0; i < A->size; i++) {
    //     printf("%d %d\n",A->data[i].data,A->data[i].priority);
    // }
    // printf("-\n");
    removeWhere(A,4);
    for (int i = 0; i < A->size; i++) {
        printf("%d %d\n",A->data[i].data,A->data[i].priority);
    }



}
