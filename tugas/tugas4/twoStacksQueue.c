#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int arr[10];
    int size;
    int top;
} Stack;

Stack * initStack() {
    Stack * newStack = malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->top = -1;

    return newStack;
}

int isFull(Stack *stack) {
    if (stack->top == 10-1) {
        return 1;
    }
    return 0;
}


int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}


void push(Stack *stack,int data) {
    stack->arr[stack->top+1] = data;
    stack->size++; stack->top++;
}

int pop(Stack *stack) {
    int retData = stack->arr[stack->top];
    stack->size--; stack->top--;
    return retData;
}

void moveAll(Stack *stackFrom, Stack* stackTo) {
    while (!isEmpty(stackFrom) && !isFull(stackTo)) {
        int dataMov = pop(stackFrom);
        push(stackTo,dataMov);
    }
}


typedef struct twoStackQueue {
    Stack * in;
    Stack * out;
    int size;
} TSQueue;

TSQueue * initQueue() {
    TSQueue * newQ = malloc(sizeof(TSQueue));
    newQ->in = initStack();
    newQ->out = initStack();
    newQ->size = 0;
}

int Enqueue(TSQueue *queue,int data) {
    if (queue->size != 0) {
        if (isEmpty(queue->in)) {
            moveAll(queue->out,queue->in);
        }
    }

    push(queue->in,data);
    queue->size++;
}

int Dequeue(TSQueue *queue) {
    if (queue->size != 0) {
        if (isEmpty(queue->out)) {
            moveAll(queue->in,queue->out);
        }
    }

    pop(queue->out);
    queue->size--;
}


int main() {


    TSQueue *q = initQueue();
    
    Enqueue(q,1);
    Enqueue(q,2);
    Enqueue(q,3);
    Enqueue(q,4);
    
    Dequeue(q);

    Stack *n =q->in;
    if (!isEmpty(q->out)) n = q->out;
    printf("Top -> ");
    for (int i = n->top; i > -1;i--) {

        printf("%d ",n->arr[i]);
    }
    printf("-> Bottom\n");

    Enqueue(q,5);

    Dequeue(q);

    n =q->out;
    // if (!isEmpty(q->out)) n = q->out;
    printf("Top -> ");
    for (int i = n->top; i > -1;i--) {

        printf("%d ",n->arr[i]);
    }
    printf("-> Bottom\n");
    




    // =========================================================================

//     Stack * A = initStack();
//     Stack * B = initStack();

//     push(A,1);
//     push(A,5);
//     push(A,8);
//     push(A,2);
//     push(A,0);


//     moveAll(A,B);


//     for (int i = B->top; i > -1;i--) {

//         printf("%d\n",B->arr[i]);
//     }

}