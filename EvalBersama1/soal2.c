// Antrian panggilan darurat dengan prioritas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int last_aidi = 87970;
int timestamp = 0;

typedef struct Node
{
    int priority;
    int id;
    char nama[30];
    int timestamp;

    struct Node * prev;
    struct Node * next;
} node ;


typedef struct priorityQueue {
    node * head;
    node *tail;
    int size;
} PQueue;


PQueue *initQueue() {
    PQueue *newQ = malloc(sizeof(PQueue));

    newQ->head = NULL;
    newQ->tail = NULL;
    newQ->size = 0;

    return newQ;
}

int isEmpty(PQueue *queue) {
    if (queue->size == 0 ) return 1;
    return 0;
}

// int isFull(PQueue* queue) {
//     if (queue->size == 10 ) return 1;
//     return 0;
// }

void swapN(node * add1,node * add2) {
    
    char svNm[30]; strcpy(svNm,add1->nama);
    int svPr = add1->priority;
    int svTms = add1->timestamp;
    int svId = add1->id;

    // add1->data = add2->data;
    strcpy(add1->nama,add2->nama);
    add1->priority = add2->priority;
    add1->timestamp = add2->timestamp;
    add1->id = add2->id;

    strcpy(add2->nama,svNm);
    add2->priority = svPr;
    add2->id = svId;
    add2->timestamp = svTms;
}




void push(PQueue * queue, char nama[],int priority) {
    node * newNode = malloc(sizeof(node));

    newNode->id = last_aidi++;
    newNode->timestamp = timestamp++;

    strcpy(newNode->nama,nama);
    newNode->priority = priority;

    newNode->prev = NULL;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        printf("a\n");
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        printf("lsakd\n");
        newNode->prev = queue->tail;
        queue->tail->next = newNode;
        queue->tail = newNode;
        // queue->tail = queue->tail->next

        node * now = queue->tail;

        while(now != queue->head) {
            // if (now->prev == NULL) {
            //     break;
            // }
            // printf("%d %d\n",now->priority,now->prev->priority);
            if (now->priority < now->prev->priority) {
                printf("swapping\n");
                swapN(now,now->prev);
            }
            // if (now->timestamp < now->prev->timestamp) {
            //     printf("swapping\n");
            //     swapN(now,now->prev);
            // }

            now = now->prev;
            // if (queue->data[now].priority < queue->data[now-1].priority) {
            //     swapN(&queue->data[now], &queue->data[now-1]);
            //     now-=1;
            // }
            //  else break;




        }

        
    }
    
    queue->size++;
}


// void shiftArrToLeft(PQueue *queue) {
//     for (int i = 0; i < queue->size-1;i++) {
//         swapN(&queue->data[i],&queue->data[i+1]);
//     }
// }

node * pop(PQueue *queue) {

    if (isEmpty(queue)) {
        
        printf("empt\n");
        return NULL;
    };

    // int retVal = queue->data[queue->head].data;
    node * retval = queue->head;
    queue->head = queue->head->next;
    // queue->head->next->prev = NULL;
    // queue->head->prev = NULL;
    

    // shiftArrToLeft(queue);


    queue->size--;
    // queue->tail--;
    return retval;
}

// void removeAtN(PQueue *queue, int nth) {
//     int i = nth;
//     while (i < )
// }

// void removeWhere(PQueue *queue,int toRm) {
//     int i = 0;
//     while (1) {

//         if (queue->data[i].data == toRm) {
//             int j = i;
//             while (j < queue->size-1) {
//                 swapN(&queue->data[j],&queue->data[j+1]);
//                 j++;
//             }
//             queue->size--;
//             queue->tail--;
//         }
        
//         if (i == queue->tail) break;

//         i++;
//     }
// }


// int main() {

//     PQueue *A = initQueue();
//     push(A,1,2);
//     push(A,2,3);
//     push(A,3,1);
//     push(A,4,2);
//     push(A,4,1);
//     push(A,5,1);
//     push(A,6,4);
//     push(A,4,3);
//     push(A,7,4);
//     push(A,8,1);
//     push(A,5,3);
//     pop(A);
//     pop(A);
//     pop(A);
//     // for (int i = 0; i < A->size; i++) {
//     //     printf("%d %d\n",A->data[i].data,A->data[i].priority);
//     // }
//     // printf("-\n");
//     removeWhere(A,4);
//     for (int i = 0; i < A->size; i++) {
//         printf("%d %d\n",A->data[i].data,A->data[i].priority);
//     }



// }




int main() {
    PQueue *  A = initQueue();

    // push(A,"ai",2);
    // push(A,"mia",1);
    // push(A,"tima",3);
    // push(A,"ia",1);
    // push(A,"tua",2);
    // push(A,"apo",3);

    // printf("%d",A->head);
    // printf("\n\n");



    int command = 0;


    while (command != 4) {
        printf( "1. Tambah laporan baru\n"
                "2. Proses laporan (hapus dari list dan tampilkan datanya)\n"
                "3. Tampilkan semua laporan dalam antrean\n"
                "4. Keluar dari program\n"
        );
        scanf("%d", &command);

        switch (command)
        {
        case 1:
            int prior;
            char nama[30];
            printf("format: prioritas nama \n");
            scanf("%d %s",&prior, &nama);

            push(A,nama,prior);

            break;

        case 2:
            node * now = pop(A);
            printf("%d\n",now->id);
            printf("%s\n",now->nama);
            printf("%d\n",now->priority);
            printf("%d\n\n",now->timestamp);
        
            break;
        case 3:
        node * now2 = A->head;
        while (1){
        // for (node * now = A->head; now->next != NULL; now = now->next) {;
            printf("%d\n",now2->id);
            printf("%s\n",now2->nama);
            printf("%d\n",now2->priority);
            printf("%d\n\n",now2->timestamp);
            if (now2 != A->tail) {
                now2 = now2->next;
            } else break;

        }

        case 4:
        break;
            
        default:
            break;
        }

    }

    // node * now = A->head;
    // while (1){
    // // for (node * now = A->head; now->next != NULL; now = now->next) {;
    //     printf("%d\n",now->id);
    //     printf("%s\n",now->nama);
    //     printf("%d\n",now->priority);
    //     printf("%d\n\n",now->timestamp);

    //     now = now->next;

    // }


}