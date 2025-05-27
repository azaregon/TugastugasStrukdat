#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node * prev;
    int data;
    int isMe;
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

typedef struct RETDAT {
    int data;
    int isMe;
}  RetDat; 


// void pushBack(LinkedList * ll, int data) {
//     node * newNode = malloc(sizeof(node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (ll->size == 0) {
//         newNode->prev = NULL;
//         ll->head = newNode;
//         ll->tail = newNode;

        

//     } else {
//         newNode->prev = ll->tail;
//         ll->tail->next = newNode;
//         ll->tail = newNode;
//     }
//     ll->size++;

// }

void pushFront(LinkedList * ll, int data,int isMe) {
    node * newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->isMe = isMe;
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
    }
    ll->size++;

}


RetDat popBack(LinkedList *ll) {
    node * teil = ll->tail;

    RetDat retVal;
    retVal.data = teil->data;
    retVal.isMe = teil->isMe;

    if (teil == NULL) {
        return retVal;
    } else if (ll->size == 1 ||( teil->next == NULL && teil->prev == NULL)) {
        ll->head = NULL;
        ll->tail = NULL;
        ll->size--;

        return retVal;
    } else {
        teil->prev->next = NULL;
        ll->tail = teil->prev;

        free(teil);

        ll->size--;
        return retVal;

    }
}



int main() {
    LinkedList * q = initLL();

    int ToAn,ByBr,AnKm;
    int ToAnKm = 0;
    scanf("%d %d %d",&ToAn,&ByBr,&AnKm);


    for (int i = 0; i < ToAn; i++) {
        int inginBr;

        scanf("%d", &inginBr);

        if (i == ToAn-1){
            pushFront(q,inginBr,1);
        } else {
            pushFront(q,inginBr,0);
        }

    }
    // node * now = q->head;
    // for (int i = 0; i < q->size; i++) {
    //     printf("[%d %d] -> ",now->data,now->isMe);
    //     now = now->next;
    // }

    int iteration = 0;
    while (ByBr > 0 || !q->size == 0) {
        iteration++;

        // printf("%d    | ",ByBr);
        // node * now = q->head;
        // for (int i = 0; i < q->size; i++) {
        //     printf("[%d %d] ->",now->data,now->isMe);
        //     now = now->next;
        // }
        // printf("\n");

        RetDat popped = popBack(q);

        

        if (iteration % AnKm == 0 ) {
            pushFront(q,popped.data,popped.isMe);
            ToAnKm++;
        } else {
            // if (popped.isMe == 1 && ByBr>popped.data) {
            //     printf("%d Yes Dapat burger gratis!!!",ToAnKm);
            //     return 1;
            // }
            ByBr-= popped.data;    
            
        }
        
        // printf("\n");
        // printf("%d    | ",ByBr);
        // node * now = q->head;
        // for (int i = 0; i < q->size; i++) {
            //     printf("[%d %d] ->",now->data,now->isMe);
            //     now = now->next;
            // }
    }
        
        
    if (ByBr > 0) {
        printf("%d Yes Dapat burger gratis!!!",ToAnKm);
    } else {

        printf("%d NOO tidak Dapat :(", ToAnKm);
    }



} 