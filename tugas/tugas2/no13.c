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
    unsigned size;
} LinkedList ;


LinkedList * initLL() {
    LinkedList * newLL = malloc(sizeof(LinkedList));
    newLL->size = 0;
    return newLL; 
}


char head(LinkedList * ll) {
    // printf("%c\n",ll->head->data);
    return ll->head->data;
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
    }
    ll->size--;
}

char pop(LinkedList * ll) {
    char headVal = head(ll);
    deleteFront(ll);

    return headVal;
}

void put(LinkedList * ll, char data) {
    node * newNode = malloc(sizeof(node));
    
    newNode->data = data;
    newNode->next = ll->head;
    ll->head = newNode;


    ll->size++;

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




int main() {
    // LinkedList * w1 = initLL();
    // LinkedList * w2 = initLL();

    // char a[30];
    // char b[30];

    // scanf("%s",&a);
    // scanf("%s",&b);

    // for (int i = strlen(a); i >0; i--){
    //     pushBack(w1,a[i]);
    // }
    
    // for (int i = 0; i < strlen(b); i++){
    //     pushBack(w2,b[i]);
    // }
    
    LinkedList * angka1 = initLL();
    LinkedList * angka2 = initLL();
    LinkedList * hasilSt = initLL();

    char a1[10] = "258935";
    char a2[10] = "896523";
    for (int i = 0; i < strlen(a1);i++) {
        put(angka1,a1[i]);
        put(angka2,a2[i]);
    }
    
    int carry = 0;
    for (int i = 0; i < strlen(a1);i++) {
        int digit1 = pop(angka1);
        int digit2 = pop(angka2);
        int hasil = ((int)digit1-(int)'0') + ((int)digit2-(int)'0') + carry;
        put(hasilSt,(char)(hasil%10 + (int)'0'));
        
        if (hasil > 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        
    }
    if (carry) {
        put(hasilSt,(char)carry+(char)'0');
    }
    printLL(hasilSt);
    
    // put(angka1,'1');
    // put(angka1,'2');
    // put(angka1,'3');
    // put(angka1,'4');
    
    
    // printLL(angka1);
    // pop(angka1);
    // printLL(angka1);
    // pop(angka1);
    // printLL(angka1);
    // pop(angka1);
    // printLL(angka1);
    // pop(angka1);
    // printLL(angka1);





    return 1;
}