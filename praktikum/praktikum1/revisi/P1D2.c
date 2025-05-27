#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// typedef struct Stack {
//     int top;
//     int stack[150];
// } stack;

// stack * initSt() {
//     stack * a = malloc(sizeof(stack));
//     a->top = -1;

//     return a;
// }

// int top(stack * stek) {
//     return stek->stack[stek->top];
// }

// void push(stack * stek , int data) {
//     stek->stack[stek->top+1] = data;
//     stek->top++;
// }

// int pop(stack * stek) {
//     int retVal = stek->stack[stek->top];
//     stek->top--;

//     return retVal;
// }

// #include <stdio.h>
// #include <stdlib.h>

typedef struct node {
    struct node * prev;
    int data;
    struct node * next;
} node;


typedef struct LinkedList{
    node * head;
    node * tail;
    unsigned size;
} LinkedList ;


LinkedList * initLL() {
    LinkedList * newLL = malloc(sizeof(LinkedList));
    newLL->size = 0;
    return newLL; 
}


void pushBack(LinkedList * ll, int data) {
    node * newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (ll->size == 0) {
        newNode->prev = NULL;
        ll->head = newNode;
        ll->tail = newNode;

        

    } else {
        newNode->prev = ll->tail;
        ll->tail->next = newNode;
        ll->tail = newNode;
    }
    ll->size++;

}

void pushFront(LinkedList * ll, int data) {
    node * newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (ll->size == 0) {
        newNode->prev = NULL;
        ll->head = newNode;
        ll->tail = newNode;

        

    } else {
        newNode->next = ll->head;
        ll->head->prev = newNode;
        ll->head = newNode;

        node *nowTu = ll->head;
        while (nowTu->next != NULL && nowTu->data < nowTu->next->data) {
            int sv = nowTu->data;
            nowTu->data = nowTu->next->data;
            nowTu->next->data = sv;

            nowTu = nowTu->next;
        }
    }
    ll->size++;

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
//     stack * stek = initSt();
//     stack * stek2 = initSt();
    
    LinkedList * LL = initLL();
    int toData, E;
    scanf("%d %d", &toData,&E);
    
    for (int i = 0; i < toData;  i++) {
        char encr[10];
        scanf("%s",&encr);
        
        int decr = cvrt(encr);
        
        // printf("%d  -- ",decr);
        // pushBack(LL,decr);
        pushFront(LL,decr);
        // push(stek,decr);
        
        // printf(" | ");
        // for (int i = 0; i <= stek->top; i ++) {
        //     printf(" %d,", stek->stack[i]);

        // }

        // printf("|  ");
        // printf("%d  ",E);
        // if (top(stek) >= E ) {
        //     while ( stek->top > -1 ) {
        //         if (top(stek) >= E) {
        //             printf("%d ",pop(stek));
        //         }
        
        
        //         E--;
        //     }
            
        // }

        // printf("len: %d\n",LL->size);
        // node * now2 = LL->head;
        // // while (now2->next != NULL){
        // for (int i = 0; i < LL->size; i++){
        //     printf("%d,, ", now2->data);
        //     now2 = now2->next;
        // }
        // printf("\n");
        
        node * now = LL->tail;
        // while (now->prev != NULL ) {// || now != NULL) {
            // for (int i = 0; i < LL->size; i++){// || now != NULL) {
        // while (now != NULL ) {// || now != NULL) {
        do {// || now != NULL) {
            // printf("%d   ",now->data);
            if (now->data == E) {
                // printf("removed %d ] ",i);
                //remove at i
                // printf("[%d] %d ",now->data);
                printf("%d ",now->data);
                node * toDel = now;

                if (now->next == NULL && now->prev == NULL) {
                    LL->head = NULL;
                    LL->tail = NULL;
                    now = NULL;
                } else if (now == LL->tail) {
                    // printf("isTail");
                    if (now->prev == NULL && now->next == NULL) {
                        LL->head == NULL;
                        LL->tail == NULL;
                    } else {
                        now = now->prev;
                        LL->tail = now;
                        now->next = NULL;
                    }
                    
                } else if (now == LL->head) {
                    // printf("isHead");
                    if (now->prev == NULL && now->next == NULL) {
                        LL->head == NULL;
                        LL->tail == NULL;
                    } else {
                        now = now->next;   
                        LL->head = now;
                        now->prev = NULL;
                    }
                } else {
                    now->prev->next = now->next;
                    now->next->prev = now->prev;
                    now = now->next;
                }
                E--;
                LL->size--;
                free(toDel);
            } else {
                now = now->prev;
            }
        } while (now != NULL );
        
        printf("\n");
        // printf("\n");
    }


    // for (int i = 0; i < tD; i++){
    //     if ()
    // }
    
    
}
