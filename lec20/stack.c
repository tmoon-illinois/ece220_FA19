#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node{
    int id;
    double data;
    node *next;
};


void printList(node *headptr)
{
    node *current = headptr->next;
    int cnt=0;
    printf("=======================================\n");
    while(current!=NULL){
        printf("node%d: id=%d, data=%lf\n", cnt, current->id, current->data);
        cnt++;
        current = current->next;
    }
    printf("\n\n");
}

node *searchID(node *headptr, int id)
{
    // Initialize previous, current pointer at the beginning of the list
    node *previous = headptr;
    node *current = headptr->next;
    // Travers list
    while( current != NULL ){
        if(current->id == id)
            return previous;
        previous = current;
        current = current->next;
    }
    // Nothing found
    return NULL;
}

node pop(node *headptr)
{
    // current = head node
    node *current = headptr->next;
    // Detect underflow
    if(current == NULL){
        printf("Stack underflow.\n");
        exit(1);
    }
    // Prepare to return the head node
    node Data;
    Data.id = current->id;
    Data.data = current->data;
    // head pointer points the second node
    headptr->next = current->next;
    // remove the head node
    free(current);
    return Data;

}

//void prependNode(node *headptr, node *Data)
void push(node *headptr, node *Data)
{
    // create a new node
    node *new = (node*) malloc(sizeof(node));
    new->id = Data->id;
    new->data = Data->data;
    // point to the original head node
    new->next = headptr->next;
    // head pointer points to the new node
    headptr->next = new;
}
int main()
{
    node top;
    top.next = NULL;

    node temp;
    temp.id = 1;
    temp.data = 1.5;
    push(&top, &temp);
    
    temp.id = 2;
    temp.data = 2.5;
    push(&top, &temp);

    printList(&top);

    node Data = pop(&top);
    printf("popped data: id=%d, data=%lf\n", Data.id, Data.data);
    printList(&top);

    Data = pop(&top);
    printf("popped data: id=%d, data=%lf\n", Data.id, Data.data);
    printList(&top);
    
    Data = pop(&top);
    printf("popped data: id=%d, data=%lf\n", Data.id, Data.data);
    printList(&top);
}
