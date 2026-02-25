#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *start = NULL, *ptr, *newNode;
    int i, value;

    if (n <= 0)
        return NULL;

    printf("Enter data for node 1: ");
    scanf("%d", &value);

    start = (struct Node*)malloc(sizeof(struct Node));
    start->data = value;
    start->next = NULL;
    ptr = start;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        ptr->next = newNode;
        ptr = newNode;
    }

    return start;
}
void displayList(struct Node *start) {
    struct Node *ptr = start;

    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* deleteAfter(struct Node *start,int key){
    struct Node *ptr=start,*temp;

    while(ptr && ptr->data!=key)
        ptr=ptr->next;

    if(ptr && ptr->next){
        temp=ptr->next;
        ptr->next=temp->next;
        free(temp);
    }else{
        printf("Deletion not possible\n");
    }
    return start;
}

void display(struct Node *start){
    while(start){
        printf("%d -> ",start->data);
        start=start->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *start=NULL;
    int n,i,val,key;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        start=insert(start,val);
    }

    printf("Delete after value: ");
    scanf("%d",&key);

    start=deleteAfter(start,key);

    display(start);
}