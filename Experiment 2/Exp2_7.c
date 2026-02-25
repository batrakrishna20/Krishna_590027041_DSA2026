#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* insertEnd(struct Node* start,int val){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=val;

    if(!start){
        newNode->next=newNode;
        return newNode;
    }

    struct Node *ptr=start;
    while(ptr->next!=start) ptr=ptr->next;

    ptr->next=newNode;
    newNode->next=start;
    return start;
}

struct Node* insertBegin(struct Node* start,int val){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=val;

    if(!start){
        newNode->next=newNode;
        return newNode;
    }

    struct Node *ptr=start;
    while(ptr->next!=start) ptr=ptr->next;

    ptr->next=newNode;
    newNode->next=start;
    return newNode;
}

struct Node* deleteBegin(struct Node* start){
    if(!start) return NULL;

    if(start->next==start){
        free(start);
        return NULL;
    }

    struct Node *last=start;
    while(last->next!=start) last=last->next;

    struct Node *temp=start;
    last->next=start->next;
    start=start->next;
    free(temp);
    return start;
}

struct Node* deleteEnd(struct Node* start){
    if(!start) return NULL;

    if(start->next==start){
        free(start);
        return NULL;
    }

    struct Node *ptr=start,*prev=NULL;
    while(ptr->next!=start){
        prev=ptr;
        ptr=ptr->next;
    }

    prev->next=start;
    free(ptr);
    return start;
}

void display(struct Node *start){
    if(!start){
        printf("List empty\n");
        return;
    }

    struct Node *ptr=start;
    int count=0;

    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
        count++;
    }while(ptr!=start);

    printf("\nTotal nodes = %d\n",count);
}

int main(){
    struct Node *start=NULL;
    int ch,n,val,i;

    printf("1 Insert Begin\n2 Insert End\n3 Delete Begin\n4 Delete End\n");
    printf("Enter choice: ");
    scanf("%d",&ch);

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        start=insertEnd(start,val);
    }

    if(ch==1){
        printf("Enter value to insert at beginning: ");
        scanf("%d",&val);
        start=insertBegin(start,val);
    }
    else if(ch==2){
        printf("Enter value to insert at end: ");
        scanf("%d",&val);
        start=insertEnd(start,val);
    }
    else if(ch==3){
        start=deleteBegin(start);
    }
    else if(ch==4){
        start=deleteEnd(start);
    }

    printf("\nResult List:\n");
    display(start);
}