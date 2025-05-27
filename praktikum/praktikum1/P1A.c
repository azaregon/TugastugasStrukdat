#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack {
    int top;
    char stack[150];
} stack;

stack * initSt() {
    stack * a = malloc(sizeof(stack));
    a->top = 0;

    return a;
}


void push(stack * stek , char data) {
    stek->stack[stek->top+1] = data;
    stek->top++;
}

char pop(stack * stek) {
    char retVal = stek->stack[stek->top];
    stek->top--;

    return retVal;
}



int main() {


    stack * stek = initSt();


    char word[150];

    scanf("%s", &word);


    for (int i = 0; i < strlen(word); i++) {
        char now = word[i];
        // printf("%c",now);
        push(stek,word[i]);
        
        if (now == 'A' || now == 'I' || now == 'U' || now == 'E' || now == 'O' || now == 'a' || now == 'i' || now == 'u' || now == 'e' || now == 'o') {
            push(stek,word[i]);
        }
    }
    
    
    while (stek->top != 0) {
        printf("%c",pop(stek));
    }


    




}