#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct arrStack
{
    char arr[10];
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


void push(arrStack * stack, char data){
    stack->arr[stack->top+1] = data;
    stack->size++;
    stack->top++;
}

char pop(arrStack * stack) {
    if (isEmpty(stack)) {
        return 'N';
    }
    int retVal = stack->arr[stack->top];
    stack->arr[stack->top+1] = 0;
    stack->top--;
    stack->size--;

    return retVal;
}

char top(arrStack * stack) {
    if (!isEmpty(stack)) {

        return stack->arr[stack->top];
    }
    return 'N';
}




int isnumeric(char n) {
    return ((int) n >= 48 && (int) n <= 57)? 1 : 0;
}

int operator_hierarchy(char o) {
    switch (o)
    {
    case '-':
        return 1;
        break;
    case '+':
        /* code */
        return 1;
        break;
    case '*':
        /* code */
        return 2;
        break;
    case '/':
        /* code */
        return 2;
        break;
    case '(':
        /* code */
        return -1000;
        break;
    case ')':
        /* code */
        return 101;
        break;
    // case '-':
    //     /* code */
    //     break;
    // case '-':
    //     /* code */
    //     break;
    
    default:
        return -999;
        break;
    }
}


char * intopostFIX(char expr[]) {
    
    arrStack * opStack = initStack();

    char postFix[64] = "";
    // char * postFix = malloc(sizeof(char)*64);

    int postFixAppend = 0;

    int brckts_cnt = 0;

    for (int i = 0; i < strlen(expr); i++) {
        // printf("%d: ",i);
        char chNow = expr[i];
        // printf("%c ",chNow);
        // printf(" -%d- ",opStack->top);
        // printf("%c\n",top(opStack));
        int operator_hier = operator_hierarchy(chNow);

        
        if (isnumeric(chNow)) {
            postFix[postFixAppend] = chNow;
            postFixAppend+=1;
        } else if (chNow == '(') {
            push(opStack,chNow);
            brckts_cnt++;
            
        } else if (chNow == ')') {
            brckts_cnt++;

            while (1) {
                char poppedTop = pop(opStack);

                if (poppedTop == '(') {
                    break;
                }

                if (isEmpty(opStack)) {
                    break;
                }

                postFix[postFixAppend] = poppedTop;
                postFixAppend+=1;
            } 

        } else if (operator_hier != -999) {
            int stackTopOpHier = operator_hierarchy(top(opStack));

            if (stackTopOpHier >= operator_hier) {
                char popped = pop(opStack);
                
                postFix[postFixAppend] = popped;
                postFixAppend+=1;
            }
            push(opStack,chNow);
        }
        // printf("%s\n",postFix);
        // printf("\n");
    }

    while (!isEmpty(opStack)) {
        char popped = pop(opStack);
        postFix[postFixAppend] = popped;
        postFixAppend+=1;
    }

    if (brckts_cnt % 2 != 0) {
        // printf();
        return "bracket was never closed";
    }

    char * ret = malloc(sizeof(char)*64);
    memcpy(ret,postFix,sizeof(char)*64);
    return ret;

}

int evaluatePostfix(char postFix[]) {
    arrStack * numStack = initStack();

    // int res = 0;
    for (int i = 0; i < strlen(postFix); i++ ) {
        char chNow = postFix[i];

        if (isnumeric(chNow)) {
            push(numStack,chNow);
        } else {
            printf("chch: %c\n",top(numStack));
            int num1 = (int) pop(numStack) - (int) '0';
            int num2 = (int) pop(numStack) - (int) '0';
            
            int tempSv = 0;
            switch (chNow) {
                case '+':
                tempSv= num1+num2;
                break;
                
                case '-':
                tempSv = num1-num2;
                break;
                
                case '*':
                tempSv = num1*num2;
                break;
                
            case '/':
                tempSv = num1/num2;
                break;
                
            // case '+':
            //     push(numStack,num1+num2);
            //     break;
            
            default:
            break;
        }
        printf("%d %c %d = %d\n",num1, chNow, num2,tempSv);
        push(numStack,(char)(tempSv+(int)'0'));

        }


    }
    return (int) top(numStack) - (int) '0';

}


int main() {
    char expr[64] = "( 2 + 3 ) * ( 8 / 4 ) - 6";
    // char expr[64] = "3+2*8";

    char * postFix = intopostFIX(expr); 

  
    printf("%s \n",postFix);
    printf("%d \n",evaluatePostfix(postFix));


    return 1;
}

//         if (operator_hier ==  100 ) { // == (
//             brckts_cnt++;
//             push(opStack,chNow);
//         }
//         else if ( operator_hier == 101) { // == )
//             while (top(opStack) != '(') {
//                 char topS[2] = {pop(opStack)};
//                 strcat(postFix,topS);
//             }
//             pop(opStack);
//         }
//         else {
//             while ( !isEmpty(opStack) && operator_hier <= operator_hierarchy(top(opStack))) {
//                 char topS[2] = {pop(opStack)};
//                 strcat(postFix,topS);
//             }
//             push(opStack,chNow);

//         }

//         while (!isEmpty(opStack)) {
//             char topS[2] = {pop(opStack)};
//             strcat(postFix,topS);
//         }

//         printf("%s",postFix);
//         // printf("\"%c\" -> %d || %d\n",expr[i],isnumeric(expr[i]),isoperator(expr[i]) );
//     }

    // if (brckts_cnt % 2 != 0) {
    //     printf("bracket is not closed");
    //     return 1;
    // }



    // return 1;
// }