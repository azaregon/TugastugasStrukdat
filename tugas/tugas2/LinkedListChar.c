#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    char data;
    struct node * next;
} ;

typedef struct node node;


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

// void init(LinkedList* ll,char data) {
//     node * newNode = malloc(sizeof(node));
//     newNode->data = data;
//     ll->head = newNode;
//     ll->tail = newNode;
//     ll->size = 1;

// }

void head(LinkedList * ll) {
    printf("%c\n",ll->head->data);
}

void tail(LinkedList * ll) {
    printf("%c\n",ll->tail->data);
}


void pushBack(LinkedList * ll, char data) {
    // node * tailNode = ll->tail;
    node * newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (ll->size == 0) {
        ll->head = newNode;
        ll->tail = newNode;

    } else {
        ll->tail->next = newNode;
        ll->tail = newNode;
    }
    ll->size++;

}

void deleteFront(LinkedList * ll) {
    if (ll->size > 1) {

        node * currHead = ll->head;
        node * newHead = currHead->next;
        ll->head = newHead;
        free(currHead);
    } else {
        node * currHead = ll->head;
        free(currHead);
        ll->head = NULL;
        ll->tail = NULL;
    }
    ll->size--;
}

void deleteBack(LinkedList * ll) {
    if (ll->size == 1) {
        node * currHead = ll->head;
        free(currHead);
        ll->head = NULL;
        ll->tail = NULL;
    }
    node * currNode = ll->head;
    node * nextNode = currNode->next;

    // bcause our pointer is pointing to the node before deletion, so index is minus one
    while (nextNode->next != NULL)
    {
        // printf("%c  ",currNode->data);
        currNode = currNode->next;
        nextNode = currNode->next;

    }
    currNode->next = nextNode->next;
    ll->tail = currNode;
    free(nextNode);
    ll->size--;
}

void deleteAtI(LinkedList * ll,int index) {
    if (index == 0) {
        deleteFront(ll);
        return;

    } else if (index == ll->size-1 || index == -1) {
        deleteBack(ll);
        return;
    } else if (index >= ll->size) {
        printf("index out of range\n");
        return;
    }


    // unsigned sz = ll->size;
    node * currNode = ll->head;
    node * nextNode = currNode->next;

    // bcause our pointer is pointing to the node before deletion, so index is minus one
    for (unsigned i = 0; i < index-1; i++) {
        // printf("%c  ",currNode->data);
        currNode = currNode->next;
        nextNode = currNode->next;

    }
    currNode->next = nextNode->next;
    free(nextNode);
    ll->size--;
    // node * newNextNode = currNode->next; 
}

void printLL(LinkedList * ll) {
    unsigned sz = ll->size;
    node * currNode = ll->head;

    for (unsigned i = 0; i < sz; i++) {
        printf("%c  ",currNode->data);
        currNode = currNode->next;
    }
    printf("\n");

}



unsigned findData(LinkedList * ll, char data) {
    unsigned iterator = 0;
    node * currNode = ll->head;
    while (iterator < ll->size) {
        if (currNode->data == data) {
            return iterator;
        }
        currNode = currNode->next;
        iterator++;
    }

    return -1;
}

int deleteData(LinkedList * ll, char data) {
    
    // to preserve previous data address, currnode is node before, nextnode is our point

    node * currNode = ll->head;
    node * nextNode = currNode->next;

    for (int i = 0; i < ll->size; i++) {
        if (i == 0 && currNode->data == data) {
            deleteFront(ll);

            return 1;
        }

        if (nextNode== NULL){
            return -1;
        }
        
        if (nextNode->data == data) {
            currNode->next = nextNode->next;
            free(nextNode);
            ll->size--;
            return 1;
        } 
        currNode = currNode->next;
        nextNode = currNode->next;
    }
    return -1;

}
int main() {

    // LinkedList * LL = malloc(sizeof(LinkedList));
    LinkedList * LL = initLL();
    
    // init(LL);
    // printf("%d\n",LL->size);
    pushBack(LL,'a');
    // printf("%d\n",LL->size);
    pushBack(LL,'l');
    // printf("%d\n",LL->size);
    pushBack(LL,'c');
    pushBack(LL,'c');
    // printf("%d\n",LL->size);
    pushBack(LL,'d');
    // printf("%d\n",LL->size);

    deleteFront(LL);
    printLL(LL);
    deleteFront(LL);
    printLL(LL);
    deleteFront(LL);
    printLL(LL);
    deleteFront(LL);
    printLL(LL);
    deleteFront(LL);
    printLL(LL);
    // deleteAtI(LL,3);

    // unsigned c = findData(LL,'c');
    // printf("%u\n",c);
    
    // printLL(LL);
    // deleteData(LL,'c');

    // head(LL);
    // tail(LL);


    // printLL(LL);


}