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

int isEmpty(arrStack * stack) {
    if (stack->size == 0) {
        return 1;
    } 
    return 0;
}

int top(arrStack * stack ) {
    return stack->arr[stack->top];
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

int search(arrStack * stack, int data) {
    arrStack * temp = initStack();

    // printf("%d\n",stack->size );
    
    while (top(stack) != data) {
        push(temp,top(stack));
        pop(stack);
    }

    int index = stack->top;
    
    while (temp->top != -1) {
        push(stack,pop(temp));
    }
    // printf("%d\n",stack->size );


    return index;
}

void edit(arrStack * stack, int dataAwal, int dataGanti) {
    arrStack * temp = initStack();

    // printf("%d\n",stack->size );
    
    while (top(stack) != dataAwal) {
        push(temp,top(stack));
        pop(stack);
    }

    pop(stack);
    push(stack,dataGanti);
    
    while (temp->top != -1) {
        push(stack,pop(temp));
    }
    // printf("%d\n",stack->size );
}

void editByIndex(arrStack * stack, int indexTgt, int dataGanti) {
    arrStack * temp = initStack();

    // printf("%d\n",stack->size );
    
    for (int i = 0; i < indexTgt; i++){
        push(temp,top(stack));
        pop(stack);
    }

    pop(stack);
    push(stack,dataGanti);
    
    while (temp->top != -1) {
        push(stack,pop(temp));
    }
    // printf("%d\n",stack->size );
}




void printStack(arrStack * stack) {
    arrStack * temp = initStack();

    while (!isEmpty(stack)) {
        int a = pop(stack);
        push(temp,a);
        printf("%d\n",a);
    }

    while (!isEmpty(temp)) {
        int a = pop(temp);
        push(stack,a);

    }
    printf("\n");
}

int main() {
    arrStack * stackA = initStack();

    push(stackA,6);
    push(stackA,8);
    push(stackA,7);
    push(stackA,4);
    push(stackA,10);
    push(stackA,3);

    printStack(stackA);
    
    printf("%d\n\n", search(stackA,10));
    edit(stackA,8,90);
    printStack(stackA);
    editByIndex(stackA,2,10);
    printStack(stackA);





}




