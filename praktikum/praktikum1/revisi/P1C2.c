#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node * prev;
    int data;
    struct node * next;
} node;


typedef struct LinkedList{
    node * head;
    node * tail;
    int size;
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

int main() {

    LinkedList * LL = initLL();

    int NoE;

    scanf("%d", &NoE);

    for (int i = 0 ; i < NoE; i++) {
        int DaI;
        scanf("%d", &DaI);
        pushBack(LL,DaI);
    }
    
    // node * now = LL->head;
    // for (int i = 1 ; i <= NoE; i++) {
        
    //     if (i % 2 == 0) {
    //         // printf("%d \n", i);
    //         int dNow = now->data;
    //         // int dPrev = now->prev->data;
    //         now->data = now->prev->data; 
    //         now->prev->data = dNow;
    //     }
    //     now = now->next;
    // }
    
    node * now = LL->head;
    for (int i = 0 ; i < LL->size; i+=2) {
        // if (i == LL->size-1) {
        //     printf("%d",now2->data);
        // } else {
        //     printf("%d ",now2->data);
        // }
        node * a = now;
        node* b = now->next;
        if (b != NULL) {
            printf("%d %d ",b->data,a->data);
        } else {
            printf("%d", a->data);
        }

        if (i == LL->size-1) {
            break;
        }

        now = now->next->next;
        // if (now->next = NULL || now->next->next != NULL ) {
            //     now = now->next->next;
        // } else {
        //     break;
        // }
    }


}