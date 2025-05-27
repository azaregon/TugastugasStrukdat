

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



int * quickSort(int arr[],int start,int end) {

    int middle = (end-start ) / 2;

    int pivot = arr[middle];
    int Lp = 0;
    int L[middle-start];
    int Rp = middle+1;
    int R[end-middle];

    
}


int main() {
    int totalTicket, totalCustomer;

    scanf("%d %d", &totalTicket, &totalCustomer);

    int tickets[totalTicket];
    int customers[totalCustomer];

    for (int i = 0 ; i < totalTicket; i++) {
        scanf("%d", &tickets[i]);
    }

    for (int i = 0 ; i < totalCustomer; i++) {
        scanf("%d", &customers[i]);
    }


    int * sortedTickets = bubbleSort(tickets,totalTicket);
    // int * sortedCustomer = bubbleSort(customers,totalCustomer);

    // for (int i = 0; i < totalTicket; i++) {
    //     printf("%d   ",sortedTickets[i]);
    // }
    // printf("\n");

    int minTicketPriceIndex = 0;
    for (int i = 0; i < totalCustomer; i++) {
            int yes;
            
            for (int j = totalTicket; j >= 0; j--) {
                // printf("%d  ",tickets[j]);
                // if (sortedTickets[j] >= 99999999){continue;}
                if (sortedTickets[j] <= customers[i]) {
                    printf("%d\n",sortedTickets[j]);
                    sortedTickets[j] = 10000000000;
                    yes =1 ;
                    break;

                } 

                if (!yes) {printf("-1");}
                
            }

        // if (sortedCustomer[i] > sortedTickets[i]) {
        //     printf("%d", sortedCustomer[i]);
        // } else {
        //     printf("%d", -1);
        // }
    }
}