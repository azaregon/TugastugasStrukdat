// Instruksi jalan robot dengan stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    char arr[20];
    int TOS;
} Stack;


Stack * initS(){
    Stack * newS = malloc(sizeof(Stack));
    newS->TOS = -1;
}


void push(Stack * stek, char val) {
    if (stek->TOS >= 20) {
        return;
    }
    stek->TOS++;
    stek->arr[stek->TOS] = val;
    return;
}


char pop(Stack * stek) {
    if (stek->TOS == -1) {
        return -9192931;
    }
    int retVal = stek->arr[stek->TOS];
    stek->TOS--;

    return retVal;
}



int main() {
    // char command[] = "UURDBBL";
    // char command[] = "UUUBBBB";
    char command[20];
    printf("Input gerakan: ");
    scanf("%s",&command);

    Stack * commStack = initS();

    for (int i = 0 ; i < strlen(command); i++) {
        // if (strcmp(command[i],"B") != 0) {
        if (command[i] != 'B') {
            push(commStack,command[i]);
        } else {
            pop(commStack);
        }
    } 
    int x=0, y=0;
    while (commStack->TOS != -1) {
        switch (pop(commStack))
        {
        case 'U':
            y+=1;
            break;
        case 'D':
            y-=1;
            break;
        
        case 'R':
            x+=1;
            break;
        case 'L':
            x-=1;
            break;
        
        default:
            break;
        }
    }


    printf("%d, %d", x,y);
}