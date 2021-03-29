// contains operators: + - * / ^ ( )

#include "stack.h"

#define INPUT_SIZE 30

int operator_priority(char oper);

int main(void)
{
    Stack * pstack;
    Initialization(pstack);

    char input_list[INPUT_SIZE];
    scanf("%s",input_list);

    for(int i = 0; input_list[i] != '\0'; i++)
    {
        if(isalnum(input_list[i]))
        {
            putchar(input_list[i]);
            putchar(' ');
        }
        else
        {
            if(isEmpty(pstack))
                push(pstack,input_list[i]);
            else
            {
                if(input_list[i] == '^' && top(pstack) == '^')
                    push(pstack,input_list[i]); 
                else if(input_list[i] == ')')
                {
                    char current_operator = pop(pstack);
                    while(current_operator != '(')
                    {
                        putchar(current_operator);
                        putchar(' ');
                        current_operator = pop(pstack);
                    }
                }
                else
                {
                    if(top(pstack) == '(' || operator_priority(input_list[i]) < operator_priority(top(pstack)))
                        push(pstack,input_list[i]);
                    else
                    {
                        char current_operator = top(pstack);
                        while(isEmpty(pstack) == 0 && current_operator != '(' && operator_priority(input_list[i]) >= operator_priority(current_operator))
                        {
                            pop(pstack);
                            putchar(current_operator);
                            putchar(' ');
                            if(isEmpty(pstack))
                                break;
                            else
                                current_operator = top(pstack);
                        }
                        push(pstack,input_list[i]);
                    }
                }
            }
        }
    }
    while(isEmpty(pstack) == 0)
    {
        putchar(pop(pstack));
        putchar(' ');
    }
    putchar('\n');

    my_relase(pstack);
    return 0;
}

int operator_priority(char oper)
{
    switch(oper)
    {
        case '(':
            return 0;
            break;
        case '^':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}