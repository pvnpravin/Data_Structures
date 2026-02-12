// ####################################
// DOUBLY Circular Linked List
// this code is for => to avoid segementation fault if list is empty
//  @ - used to indicate the change different fron DOUBLY linear linked list
// ####################################

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;


    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL)) //  Linked list is empty
    {
        *first = newn;
        *last = newn;
    }
    else                                    // Linked list contains one or more nodes
    {
       newn->next = *first;
       (*first)->prev = newn;
       *first = newn; 
    }

    // line to maintian circular nature of Linked list
    (*last)->next = *first;
    (*first)->prev = *last;

}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;


    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL)) //  Linked list is empty
    {
        *first = newn;
        *last = newn;
    }
    else                                    // Linked list contains one or more nodes
    {
        
    }

    // line to maintian circular nature of Linked list
    (*last)->next = *first;
    (*first)->prev = *last;

}


void DeleteFirst(PPNODE first, PPNODE last)
{}
void Deletelast(PPNODE first, PPNODE last)
{}

void Display(PNODE first, PNODE last)
{
    // IMP to avoid segementation fault if list is empty
    if((first == NULL) && (last == NULL)) // linked list is empty
    {   
        printf("Linked list is Empty \n");
        return;
    }
    printf(" <=> ");
    do
    {
       printf(" | %d | <=> ", first->data);
       first = first->next;
    } while (first != last->next);

    printf("\n");
    
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if((first == NULL) && (last == NULL)) // linked list is empty
    {
        return 0;
    }
    
    do
    {
       iCount++;
       first = first->next;
    } while (first != last->next);

    printf("\n");
    
    return iCount;
}






void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{}


int main()
{   
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;
/*
    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);
*/
    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    return 0;
}
