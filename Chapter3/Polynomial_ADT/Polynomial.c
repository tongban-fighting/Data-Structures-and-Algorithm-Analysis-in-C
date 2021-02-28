#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void main(void)
{
    int coeff,exp;
    Node * my_node,* temp;
    List Poly1, Poly2, Poly_sum, Poly_prod;

    Initialization(&Poly1);
    Initialization(&Poly2);
    Initialization(&Poly_sum);
    Initialization(&Poly_prod);

    printf("For Poly1:");
    while(scanf("%d%d",&coeff,&exp))
    {
        my_node = (Node *)malloc(sizeof(Node));
        my_node->Coefficient = coeff;
        my_node->Exponent = exp;
        add_node(&Poly1,my_node);
        while(getchar() != '\n')
            continue;
    }

    while(getchar() != '\n')
        continue;
    printf("For Poly2:");
    while(scanf("%d%d",&coeff,&exp))
    {
        my_node = (Node *)malloc(sizeof(Node));
        my_node->Coefficient = coeff;
        my_node->Exponent = exp;
        add_node(&Poly2,my_node);
        while(getchar() != '\n')
            continue;
    }

    List_add(&Poly1,&Poly2, &Poly_sum);
    List_product(&Poly1,&Poly2,&Poly_prod);

    printf("Poly1 + Poly2 = ");
    temp = Poly_sum;
    while(temp != NULL)
    {
        printf("%dx^%d ",temp->Coefficient,temp->Exponent);
        temp = temp->next;
    }
    putchar('\n');
    printf("Poly1 * Poly2 = ");
    temp = Poly_prod;
    while(temp != NULL)
    {
        printf("%dx^%d ",temp->Coefficient,temp->Exponent);
        temp = temp->next;
    }
    putchar('\n');
}
