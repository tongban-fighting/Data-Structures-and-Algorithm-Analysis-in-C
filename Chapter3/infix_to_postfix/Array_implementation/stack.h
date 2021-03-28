#define ARRAY_SIZE 20

typedef char ITEM;
typedef struct Node{
    ITEM pool[ARRAY_SIZE];
    int top_position;
} Stack;


void Initialization(Stack *pstack);
void push(Stack *pstack, ITEM item);
ITEM pop(Stack *pstack);
ITEM top(Stack *pstack);
int isEmpty(Stack *pstack);
