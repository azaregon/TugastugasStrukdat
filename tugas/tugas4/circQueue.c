#include <stdio.h>
#include <stdlib.h>


typedef struct circQueue {
    int arr[10];
    int head;
    int tail;
    int size;
    int isFull;
} CQueue;


CQueue *initQ() {
    CQueue *newQ = malloc(sizeof(CQueue));
    newQ->head = 0;
    newQ->tail = 0;
    newQ->size = 0;
    newQ->isFull = 0;

}

int circIndex(int ind, char op) {
    // return abs(ind % 10);

    switch (op)
    {
    case '-':
        if (ind == 0) return (10-ind-1) %10;
        return (ind-1) % 10;
        break;

    case '+':
        return ((ind+1) % 10);
    
    default:
        break;
    }
    
}

int isFull(CQueue *queue){
    // if (queue->tail - queue->head  == 1) {
    if (circIndex(queue->head,'+') == queue->tail) {
        queue->isFull = 1;
        return 1;
    };
    queue->isFull = 0;
    return 0;
}

int isEmpty(CQueue *queue) {
    if (queue->size==0) return 1;
    return 0;
}
 
void push(CQueue *queue,int data) {
    if (isEmpty(queue)) {
        queue->arr[queue->tail] = data;
        queue->size++;
    } else if (!queue->isFull) {
        queue->tail = circIndex(queue->tail,'-');
        
        queue->arr[queue->tail] = data;
        queue->size++;
    } 

    isFull(queue);

}

int pop(CQueue *queue) {
    if (!isEmpty(queue)) {
        int retVal = queue->arr[queue->head];
        queue->arr[queue->head] = 9999;
        queue->head = circIndex(queue->head,'-');
        queue->size--;
        return retVal;
    }

    isFull(queue);


}

int  search(CQueue *queue, int data) {
    int indexRt = 0;
    int iter_cnt = 0;
    while (iter_cnt < 9) {
        int now = pop(queue);
        push(queue, now);

        if (now == data) {
            indexRt = (int)(char)iter_cnt;
        }

        iter_cnt++;
        // iter = circIndex(iter,'-');
    }

    return indexRt;
    
}

int MMA(CQueue *queue) {
    int indexRt = 0;
    int max = 0;
    int min = 1000000;
    int total = 0;
    int iter_cnt = 0;
    while (iter_cnt < 9) {
        int now = pop(queue);
        push(queue, now);

        if (now > max) max = now;
        if (now < min) min = now;
        total += now;

        iter_cnt++;
        // iter = circIndex(iter,'-');
    }

    printf("min max avg: %d %d %d\n",min,max,total/queue->size);
    return indexRt;
    
}


int edit(CQueue *queue, int data, int dataGanti) {
    int indexRt = 0;
    int iter_cnt = 0;
    while (iter_cnt < 9) {
        int now = pop(queue);
        
        if (now == data) {
            indexRt = (int)(char)iter_cnt;
            push(queue, dataGanti);
        } else {

            push(queue, now);
        }

        iter_cnt++;
        // iter = circIndex(iter,'-');
    }

    return indexRt;
    
}


int main() {
    CQueue *Q = initQ();
    // printf("%d\n",circIndex(0,'-'));


    push(Q,2);
    push(Q,1);
    // printf("%d ",Q->tail);
    // printf("\n%d %d %d\n",Q->head,Q->tail,Q->isFull);
    // printf("%d ",Q->tail);
    push(Q,3);
    push(Q,4);
    push(Q,5);
    push(Q,6);
    push(Q,7);
    push(Q,8);
    push(Q,9);
    printf("popped: %d\n",pop(Q));
    printf("popped: %d\n",pop(Q));
    printf("popped: %d\n",pop(Q));
    push(Q,10);
    push(Q,11);
    
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ",Q->arr[i]);
    // }
    // printf("\n%d %d\n",Q->head,Q->tail);
    


    printf("search result: %d\n", search(Q,8));
    
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ",Q->arr[i]);
    // }
    
    // printf("\n%d %d\n",Q->head,Q->tail);



    edit(Q,8,90);
    
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ",Q->arr[i]);
    // }
    
    // printf("\n%d %d\n",Q->head,Q->tail);
    


    MMA(Q);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ",Q->arr[i]);
    }
    
    // printf("\n%d %d\n",Q->head,Q->tail);
    
    // printf("\n%d ",Q->tail);



    return 1;



}