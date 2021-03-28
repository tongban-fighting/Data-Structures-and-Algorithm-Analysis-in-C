//Not concern about the overflow of the items

#include "stack.h"

void Initialization(Stack *pstack)
{
    pstack->pool[0] = '\0';
    pstack->top_position = -1;
}

void push(Stack *pstack, ITEM item)
{
    pstack->pool[++pstack->top_position] = item;
}

ITEM pop(Stack *pstack)
{
    return pstack->pool[pstack->top_position--];
}

ITEM top(Stack *pstack)
{
    return pstack->pool[pstack->top_position];
}

int isEmpty(Stack *pstack)
{
    if(pstack->top_position == -1)
        return 1;
    else
        return 0;
}