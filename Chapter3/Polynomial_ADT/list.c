#include "list.h"
#include <stdlib.h>

void Initialization(List * plist)
{
    *plist = NULL;
}

void add_node(List * plist, Node * pnode)
{
    if(*plist == NULL)
    {
        *plist = pnode;
        (*plist)->next = NULL;
    }
    else
    {
        Node * temp = *plist;
        Node * previous = NULL;
        while(temp != NULL)
        {
            if(temp->Exponent < pnode->Exponent)
            {
                if(previous == NULL)
                {
                    *plist = pnode;
                    pnode->next = temp;
                }
                else
                {
                    previous->next = pnode;
                    pnode->next = temp;
                }
                break;
            }
            else if (temp->Exponent == pnode->Exponent)
            {
                temp->Coefficient += pnode->Coefficient;
                break;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }
        if(temp == NULL)
        {
            previous->next = pnode;
            pnode->next = NULL;
        }
    }
}

void List_add(const List * plist1, const List * plist2, List * plist_sum)
{
    Node *temp,*newnode;
    temp = *plist1;
    while(temp != NULL)
    {
        newnode = (Node *)malloc(sizeof(Node));
        NodeCopy(temp,newnode);
        add_node(plist_sum,newnode);
        temp = temp->next;
    }
    temp = *plist2;
    while(temp != NULL)
    {
        newnode = (Node *)malloc(sizeof(Node));
        NodeCopy(temp,newnode);
        add_node(plist_sum,newnode);
        temp = temp->next;
    }
}

void List_product(const List * plist1, const List * plist2, List * plist_prod)
{
    Node * temp1, * temp2, *newnode;
    temp1 = *plist1;
    
    while(temp1 != NULL)
    {
        temp2 = *plist2;
        while(temp2 != NULL)
        {
            newnode = (Node *)malloc(sizeof(Node));
            newnode->Coefficient = temp1->Coefficient*temp2->Coefficient;
            newnode->Exponent = temp1->Exponent + temp2->Exponent;
            add_node(plist_prod,newnode);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void NodeCopy(const Node * pnode_from, Node * pnode_to)
{
    pnode_to->Coefficient = pnode_from->Coefficient;
    pnode_to->Exponent = pnode_from->Exponent;
}

void EmptytheList(List * plist)
{
    Node * temp;
    while((*plist) != NULL)
    {
        temp = (*plist)->next;
        free(*plist);
        (*plist) = temp;
    }
}