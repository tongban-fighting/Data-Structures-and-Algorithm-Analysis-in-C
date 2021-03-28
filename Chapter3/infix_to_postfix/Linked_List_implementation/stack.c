//Not concern about the overflow of the items

#include "stack.h"

void Initialization(Stack *pstack)
{
    *pstack = NULL;
}

void push(Stack *pstack, ITEM item)
{
    Node * temp = malloc(sizeof(struct sNode));
    temp->item = item;
    if(*pstack == NULL)
    {
        *pstack = temp;
        temp->next_node = NULL;
    }
    else
    {
        Node * temp2;
        temp2 = *pstack;
        *pstack = temp;
        temp->next_node = temp2;
    }
}

ITEM pop(Stack *pstack)
{
    ITEM temp = (*pstack)->item;
    Node * node_temp, * node_temp2;

    node_temp = (*pstack)->next_node;
    node_temp2 = *pstack;
    *pstack = node_temp;
    
    free(node_temp2);
    return temp;
}

ITEM top(Stack *pstack)
{
    return (*pstack)->item;
}

int isEmpty(Stack *pstack)
{
    if(*pstack == NULL)
        return 1;
    else
        return 0;
}

void relase(Stack *pstack)
{
    Node * temp;
    while(*pstack != NULL)
    {
        temp = (*pstack)->next_node;
        free(*pstack);
        *pstack = temp;
    }
}