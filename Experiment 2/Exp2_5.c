#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

struct Node* insert(struct Node *start,int val){
    struct Node *newNode=malloc(sizeof(struct Node)),*ptr;
    newNode->data=val; newNode->next=NULL;

    if(!start) return newNode;

    ptr=start;
    while(ptr->next) ptr=ptr->next;
    ptr->next=newNode;
    return start;
}

void reverseData(struct Node *start){
    int arr[200],i=0,j;
    struct Node *ptr=start;

    while(ptr){ arr[i++]=ptr->data; ptr=ptr->next; }

    ptr=start;
    for(j=i-1;j>=0;j--){ ptr->data=arr[j]; ptr=ptr->next; }
}

void display(struct Node *start){
    while(start){ printf("%d -> ",start->data); start=start->next; }
    printf("NULL\n");
}

int main(){
    struct Node *start=NULL;
    int n,i,val;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        start=insert(start,val);
    }

    printf("Original List:\n");
    display(start);

    reverseData(start);

    printf("After reversing data:\n");
    display(start);
}