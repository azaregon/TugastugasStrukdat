#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Stack {
    int top;
    int stack[150];
} stack;

stack * initSt() {
    stack * a = malloc(sizeof(stack));
    a->top = -1;

    return a;
}

int top(stack * stek) {
    return stek->stack[stek->top];
}

void push(stack * stek , int data) {
    stek->stack[stek->top+1] = data;
    stek->top++;
}

int pop(stack * stek) {
    int retVal = stek->stack[stek->top];
    stek->top--;

    return retVal;
}



int cvrt(char a[6]) {

    int retVal = 0;

    for (int i = strlen(a); i > 0; i--) {
        int tenPower = pow(10,i-1);
        // for (int j = i; j > 0; j--) {
        // int tenPower = 1;
        // for (int j = 0; j < i-1; j++) {
        //     // printf("\n%d\n",j);
        //     tenPower *= 10;
        // }

        switch (a[strlen(a)-i])
        {
        case '!':
            retVal += tenPower * 1;
            break;

        case '@':
            retVal += tenPower * 2;
            break;
        
        case '#':
            retVal += tenPower * 3;
            break;
        
        case '$':
            retVal += tenPower * 4;
            break;
        
        case '%':
            retVal += tenPower * 5;
            break;
        
        case '^':
            retVal += tenPower * 6;
            break;
        
        case '&':
            retVal += tenPower * 7;
            break;
        
        case '*':
            retVal += tenPower * 8;
            break;
        
        case '(':
            retVal += tenPower * 9;
            break;
        
        case ')':
            retVal += tenPower * 0;
            break;
        
        default:
            break;
        }
    }


    return retVal;

}

// int main(){
//     printf("%d", cvrt("!@"));
// }



int main() {
    stack * stek = initSt();
    stack * stek2 = initSt();
    
    int toData, E;
    scanf("%d %d", &toData,&E);
    
    for (int i = 0; i < toData;  i++) {
        char encr[10];
        scanf("%s",&encr);
        
        int decr = cvrt(encr);
        
        // printf("%d  -- ",decr);
        push(stek,decr);
        
        // printf(" | ");
        // for (int i = 0; i <= stek->top; i ++) {
        //     printf(" %d,", stek->stack[i]);

        // }

        // printf("|  ");
        // printf("%d  ",E);
        if (top(stek) >= E ) {
            while ( stek->top > 0 ) {
                if (top(stek) >= E) {
                    printf("%d ",pop(stek));
                }
                
                
                E--;
            }
            
        }
        
        printf("\n");
    }


    // for (int i = 0; i < tD; i++){
    //     if ()
    // }
    
    
}
