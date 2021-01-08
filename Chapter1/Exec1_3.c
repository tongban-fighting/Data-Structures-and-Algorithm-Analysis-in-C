//output real number(include negative)
#include <stdio.h>

void output_int(int inp_int);
void output_dec(double inp_dec);

int main(void)
{
    double inp;

    //let user input a real number
    printf("Please input a real number: ");
    scanf("%lf",&inp);

    //output the real number
    printf("Your input is:");

    //output sign of the real number
    if(inp < 0)
    {
        putchar('-');
        inp = inp * (-1.0);
    }

    //process the integer part
    int inp_int = (int)inp;
    output_int(inp_int);

    //process the decimal part
    double inp_dec = inp - (double)inp_int;

    if(inp_dec != 0.0)
    {
        putchar('.');
        output_dec(inp_dec);
    }

    putchar('\n');

    return 0;
}

void output_int(int inp_int)
{
    if(inp_int < 10)
    {
        printf("%d",inp_int);
        return;
    }
    output_int(inp_int/10);
    printf("%d",inp_int%10);
}

void output_dec(double inp_dec)
{
    int first_num;

    while(inp_dec != 0.0)
    {
        first_num = (int)(inp_dec*10);
        printf("%d",first_num);
        inp_dec = inp_dec * 10.0 - (double)first_num;
    }
}