#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node{
    int id;
    double data;
    node *next;
};

void prependNode(node *headptr, node *Data)
{
    node *current = headptr->next;
    // create a new node
    node *new = (node*) malloc(sizeof(node));
    new->id = Data->id;
    new->data = Data->data;
    new->next = headptr->next;

    headptr->next = new;
}

void appendNode(node *headptr, node *Data)
{
    // Initialize current with the head
    node *current = headptr->next;
    // create a new node
    node *new = (node*) malloc(sizeof(node));
    new->id = Data->id;
    new->data = Data->data;
    new->next = NULL;
    //1. If list is empty,
    if(current == NULL)
        headptr->next = new;
//        current = new;
    //2. Else find the tail
    else{
        while(current->next !=NULL)
            current = current->next;
        current->next = new;
    }
}

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

void insertNode(node *headptr)
{
    node *previous, *current;
    int id;
    printf("Enter the id to insert a new one : ");
    scanf("%d", &id);

    previous = searchID(headptr, id);
    current = previous->next;

    if(current == NULL){
        printf("ID %d is not found in the list.\n", id);
        return;
    }
    else{
        printf("ID %d is found in the list.\n", id);
        printf("Enter a new id: ");
        scanf("%d", &id);
        node *new = (node*) malloc(sizeof(node));
        new->id = id;
        new->next = current;
        previous->next = new;
    }
}

void removeNode(node *headptr)
{
    node *current;
    node *previous;

    int id;
    printf("Enter the id to remove : ");
    scanf("%d", &id);

    previous = searchID(headptr, id);
    current = previous->next;

    if(current == NULL){
        printf("%d is not found in the list.\n", id);
        return;
    }
    else{
        previous->next = current->next;
        free(current);
        printf("%d is removed in the list.\n", id);
    }
}

void removeAll(node *headptr)
{
    node *previous = headptr;
    node *current = previous->next;
    while(current !=NULL){
        printf("freed node id %d\n", current->id);
        previous->next = current->next;
        free(current);
        current = previous->next;
    }
}

int main()
{
    node base;//base empty node
    base.next = NULL;//headptr

    node temp;
    temp.id = 1;
    temp.data = 1.5;
    appendNode(&base, &temp);
    
    temp.id = 2;
    temp.data = 2.5;
    appendNode(&base, &temp);
    
    // initialize a list 
    printList(&base);
/*
    // insert a node
    insertNode(&base);
    printList(&base);

    // remove a node
    removeNode(&base);
    printList(&base);
  */

    // remove all
    removeAll(&base);
    printList(&base);
}
