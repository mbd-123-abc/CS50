//Mahika Bagri 
//31 November 2025 

#include <stdio.h>
#include <math.h>


char* getExpression(void);
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
float divide(int x, int y);
int exponent(int x, int y);

int main(void)
{
   char* expression = getExpression();
   char operation = expression[1];

   int x = expression[0] - '0';
   int y = expression[2] - '0';

   int result;

   if(operation == '+')
   {
    result = add(x, y);
   } 
   else if (operation == '-')
   {
    result = subtract(x, y);
   }   
   else if (operation == '*')
   {
    result = multiply(x, y);
   }
   else if (operation == '/')
   {
    float result = divide(x, y);
    printf("%f", result);
   }
   else
   {
    result = exponent(x, y);
   }

   printf("%i", result);
}

char* getExpression(void)
{
    char operation;
    char static expression[3];

    do
    {
        printf("Enter a 2 digit expression: ");
        scanf("%s", expression);

        operation = expression[1];
    }
    while (operation != '*' && operation != '/' && 
    operation != '+' && operation != '-' && operation != '^');

    return expression;
}

int add(int x, int y)
{
    return x+y;
}

int subtract(int x, int y)
{
    return x-y;
}

int multiply(int x, int y)
{
    return x*y;
}

float divide(int x, int y)
{
    return (float)x/y;
}

int exponent(int x, int y)
{
    return pow(x, y);
}
