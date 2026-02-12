// ####################################
// DOUBLY Circular Linked List
// this code is for => InsertAtPOS, DeleteFirst, DeleteLast, InsertFirst, InsertLast, Display, Count
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
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;   
    }

    // line to maintian circular nature of Linked list
    (*last)->next = *first;
    (*first)->prev = *last;

}


void DeleteFirst(PPNODE first, PPNODE last)
{
    if ((*first == NULL) && (*last == NULL))  // ll is empty
    {
        return;
    }
    else if (*first == *last)    // ll is haveing only one node
    {
        free(*first);

        *first == NULL;
        *last == NULL;
    }
    else                    // ll contains more than one node
    {
        *first = (*first)->next;
        free((*first)->prev);

        // line to maintian circular nature of Linked list
        (*last)->next = *first;
        (*first)->prev = *last;
    }
    
}
void Deletelast(PPNODE first, PPNODE last)
{
    if ((*first == NULL) && (*last == NULL))  // ll is empty
    {
        return;
    }
    else if (*first == *last)    // ll is haveing only one node
    {
        free(*first);

        *first == NULL;
        *last == NULL;
    }
    else                    // ll contains more than one node
    {
        *last = (*last)->prev;
        free((*last)->next);

        // line to maintian circular nature of Linked list
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

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
{
    
    int iCount = 0, i = 0;
    PNODE temp = NULL;

    iCount = Count(*first, *last);

    // Filter 
    if((pos < 1)|| (pos > iCount))
    {
        printf("Invalid Position\n");
    }

    if (pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if (pos = iCount)
    {
        Deletelast(first, last);
    }
    else
    {
       temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
    
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int iCount = 0, i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    iCount = Count(*first, *last);

    // Filter 
    if((pos < 1)|| (pos > iCount+1))
    {
        printf("Invalid Position\n");
    }

    if (pos ==1)
    {
        InsertFirst(first, last, no);
    }
    else if (pos = (iCount+1))
    {
        InsertLast(first, last, no);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));

       newn->data = no;
       newn->next = NULL;
       newn->prev = NULL;

       temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
    
}


int main()
{   
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    DeleteFirst(&head, &tail);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    Deletelast(&head, &tail);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    InsertAtPos(&head, &tail, 105,3);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    DeleteAtPos(&head, &tail,3);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d \n", iRet);

    return 0;
}
