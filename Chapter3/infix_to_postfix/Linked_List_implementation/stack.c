//Not concern about the overflow of the items

#include "stack.h"

void Initialization(Stack *pstack)
{
    *pstack = malloc(sizeof(struct sNode));
    (*pstack)->next_node = NULL;
}

void push(Stack *pstack, ITEM item)
{
    Node * temp = malloc(sizeof(struct sNode));
    temp->item = item;
    temp->next_node = (*pstack)->next_node;
    (*pstack)->next_node = temp;
}

ITEM pop(Stack *pstack)
{
    if(isEmpty(pstack))
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        ITEM temp = (*pstack)->next_node->item;
        Node * node_temp, * node_temp2;

        node_temp = (*pstack)->next_node->next_node;
        node_temp2 = (*pstack)->next_node;
        (*pstack)->next_node = node_temp;
        
        free(node_temp2);
        return temp;
    }
}

ITEM top(Stack *pstack)
{
    if(isEmpty(pstack))
        exit(EXIT_FAILURE);
    else
        return (*pstack)->next_node->item;
}

int isEmpty(Stack *pstack)
{
    if((*pstack)->next_node == NULL)
        return 1;
    else
        return 0;
}

void my_relase(Stack *pstack)
{
    Node * temp;
    while(*pstack != NULL)
    {
        temp = (*pstack)->next_node;
        free(*pstack);
        *pstack = temp;
    }
}