#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef char ITEM;
struct sNode{
    ITEM item;
    struct sNode * next_node;
};
typedef struct sNode Node;
typedef Node * Stack;


void Initialization(Stack *pstack);
void push(Stack *pstack, ITEM item);
ITEM pop(Stack *pstack);
ITEM top(Stack *pstack);
int isEmpty(Stack *pstack);
void my_relase(Stack *pstack);
