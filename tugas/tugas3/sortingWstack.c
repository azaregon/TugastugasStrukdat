#include <stdio.h>
#include <stdlib.h>


typedef struct arrStack
{
    int arr[10];
    int top;
    int size;
} arrStack;

arrStack * initStack() {
    arrStack * newStack = malloc(sizeof(arrStack));
    newStack->top = -1;
    newStack->size=0;

    return newStack;
}


void push(arrStack * stack, int data){
    stack->arr[stack->top+1] = data;
    stack->top++;
    stack->size++;
}

int pop(arrStack * stack) {
    int retVal = stack->arr[stack->top];
    stack->arr[stack->top+1] = 0;
    stack->top--;
    stack->size--;

    return retVal;
}

int head(arrStack * stack) {
    return stack->arr[stack->top];
}




int main() {
    // int stackA[10] = {8,9,2,5,7,4,1};
    // int stacB[10] = {8,9,2,5,7,4,1};

    arrStack * stackA = initStack();
    arrStack * stackB = initStack();

    // push(stackA,1);
    // push(stackA,2);
    // push(stackA,3);
    // push(stackA,44);
    push(stackA,6);
    push(stackA,8);
    push(stackA,7);
    push(stackA,4);
    push(stackA,10);
    push(stackA,3);
    // push(stackA,1);

    // push(stackA,9);
    // push(stackA,2);
    // push(stackA,5);
    // push(stackA,7);
    // push(stackA,4);
    // push(stackA,1);

    while (stackA->size > 0) {
        int temp = pop(stackA);
        
        if (stackB->size == 0 || head(stackB) > temp) {
            push(stackB,temp);
        } else {
            while (head(stackB) < temp) {
                push(stackA,head(stackB));
                pop(stackB);
                if (stackB->size == 0) break;
            }

            push(stackA,temp);

        } 

        // printf("\niter: \n");
        // for (int i = 0; i < stackA->size;i++) {
        //     printf("%d ", stackA->arr[i]);
        // }
        // printf("\n---------\n");
        // for (int i = 0; i < stackB->size;i++) {
        //     printf("%d ", stackB->arr[i]);
        // }
        // printf("\n");
    }


    while (stackB->top != -1) {
        printf("%d\n",pop(stackB));
    }




}