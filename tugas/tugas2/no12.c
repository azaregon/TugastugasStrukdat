#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {
    int number;
    struct node * next;
};

typedef struct node node;


typedef struct LinkedList {
    int size;
    node * head;
    node * tail;
} LinkedList;


LinkedList * initLL(){
    LinkedList * newLL = malloc(sizeof(LinkedList));  
    newLL->size = 0;
    return newLL;
}


void pushBack(LinkedList * ll,int val) {
    node* newNode = malloc(sizeof(node));
    newNode->number =  val;

    if (ll->size == 0) {
        ll->head = newNode;
        ll->tail = newNode;
        ll->tail->next = ll->head;
        // newNode->next = newNode;
    } else {
        ll->tail->next = newNode;
        newNode->next = ll->head;
        ll->tail = newNode;
    }

    ll->size++;
}

void removeAtData(LinkedList * ll,int data) {
    if (ll->size == 1) {
        ll->head = NULL;
        ll->tail == NULL;
        ll->size--;
        return;
    }
    node * prevNode = ll->head;
    node * currNode = prevNode->next;
    while ( currNode->number != data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    // deletion
    prevNode->next = currNode->next;
    if (currNode == ll->head) {
        ll->head = currNode->next;


    }
    free(currNode);
    ll->size--;
}

void printAllLL(LinkedList * ll) {
    node * currNode = ll->head;
    printf("Linked List: ");

    // while (1) {
    for (int i = 0; i < ll->size; i++) {

        printf("%d ",currNode->number);
        currNode = currNode->next;

        // if (currNode == ll->head->next) break;
    }
    printf("\n");
}

int main() {
    LinkedList * LL = initLL();

    int n = 5;
    int m = 2;

    for (int i = 0; i < n; i++) {
        pushBack(LL,i+1);
    }
    // printAllLL(LL);

    // printAllLL(LL);
    
    // removeAtData(LL,2);

    // printAllLL(LL);
    
    node * currNode = LL->head;

    while (LL->size != 1) {
        for (int d = 0; d < m; d++) {
            if (d == 0) continue; // the currNode is marked as 1
            
            currNode = currNode->next;
            printf("%d ",currNode->number);
        }
        printf("\n");
        node * toRm = currNode;
        currNode = toRm->next;
        printAllLL(LL);
        removeAtData(LL,(int)toRm->number);
    }
    printf("\nThe last man standing is:\n");
    printAllLL(LL);

    
}