
#include <stdio.h>

int * bubbleSort(int arr[],int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }      
        }    
    }
    
    return arr;
}


int * quickSort(int arr[],int n) {
    
}


int main() {
    
    int size;
    
    scanf("%d",&size);
    
    int unsorted[size];
    
    // printf("--------------\n");
    
    for (int i = 0; i < size; i++) {
        int a;
        // printf("%d",i);
        scanf("%d",&a);
        
        unsorted[i] = a;
    }
    int * sorted = bubbleSort(unsorted,size);
    
    int distinct = 0;
    int prev = *(sorted);
    for (int i = 1; i < size; i++) {
        if (prev != *(sorted+i)) {
            distinct++;
        }
        prev = *(sorted+i);
        
    }
    
    
    printf("\n\n%d",distinct);
    
        
}