//Mahika Bagri 
//CS50
//2 December 2025 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

char* getMethod(void);
int amountCurrency(int currency, int change, int* type);
void change(char* method, float change);
float pay(char* method);
bool checkValid(long cardNumber);
char* checkCompany(long cardNumber);
int length(long cardNumber);

int main(void)
{
    char* method = getMethod();

    float changeAmt = pay(method);
    if (changeAmt > 0)
    {
        change(method, changeAmt);
    }

    printf("Transaction complete.\n");
    printf("Thank you for shopping with us!\n");
}

char* getMethod(void)
{
    char static method[4];

    do
    {
        printf("Please select your form of payment.\n");
        printf("Cash or Card? ");
        scanf("%s", method);
    }
    while(strcmp(method, "cash") != 0 && strcmp(method, "card") != 0);

    return method;
}

float pay(char* method)
{
    float total;
    float paid;

    do
    { 
        printf("Amount to pay: ");
        scanf("%f", &total);
    }
    while(total < 0);
    
    if (strcmp(method, "cash") == 0)
    {
        do
        {
            printf("Amount paid: ");
            scanf("%f", &paid);
        }
        while(paid < total);
    }
    else 
    {
        long cardNumber;

        do 
        {
            printf("Enter card number: ");
            scanf("%ld", &cardNumber);
        }
        while(checkValid(cardNumber) || strcmp(checkCompany(cardNumber), "INVD") == 0);

        paid = total;
    }
    return paid - total;
}

bool checkValid(long cardNumber)
{
    int sum = 0;
    int n = length(cardNumber); 

    for(int i = 0; i < n; i++)
    {
        int curr = cardNumber%10;

        if (i%2 != 0)
        {
            curr = curr*2;
        }

        sum += curr; 
        cardNumber = cardNumber/10;
    }

    if (sum%10 == 0)
    {
        return true; 
    }
    else
    {
        return false;
    }
}

char* checkCompany(long cardNumber)
{
    int start2 = cardNumber/pow(10,length(cardNumber)-2);
    int start1 = cardNumber/pow(10,length(cardNumber)-1);
    
    if ((start2 == 34||start2 == 37) && length(cardNumber) == 15)
    {
        return "AMEX";
    }
    else if ((start2 == 51||start2 == 52||start2== 53||start2 == 54||
    start2 == 55) && length(cardNumber) == 16)
    {
        return "MAST";
    }
    else if (start1 == 4 && 
    (length(cardNumber) == 16||length(cardNumber) == 13))
    {
        return "VISA";
    }

    return "INVD";
}

int length(long cardNumber)
{
    int len = 0; 

    while (cardNumber > 0)
    {
        cardNumber = cardNumber/10; 
        len += 1;
    }

    return len;
}

void change(char* method, float change)
{
    int bills = 0;
    int coins = 0;
    
    int changeBills = change/1;
    int changeCoins = 100*(change - changeBills); 

    changeBills = amountCurrency(20, changeBills, &bills);
    changeBills = amountCurrency(10, changeBills, &bills);
    changeBills = amountCurrency(5, changeBills, &bills);
    changeBills = amountCurrency(1, changeBills, &bills);

    changeCoins = amountCurrency(25, changeCoins, &coins);
    changeCoins = amountCurrency(10, changeCoins, &coins);
    changeCoins = amountCurrency(5, changeCoins, &coins);
    changeCoins = amountCurrency(1, changeCoins, &coins);

    printf("%i bills change.\n", bills);
    printf("%i coins change.\n", coins);
}

int amountCurrency(int currency, int change, int* type)
{
    int numCurrency = change/currency;

    *type += numCurrency;
    change -= numCurrency*currency;

    return change;
}
