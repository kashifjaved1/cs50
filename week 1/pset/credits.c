#include <stdio.h>

int main(void)
{
    long int card;

    do
    {
        printf("Enter your Card Number: ");
        scanf("%li", &card);
    }
    while (card <= 0);

    long int check_card = card;
    int sum = 0;
    int count = 0;
    long int divider = 10;

    while (check_card > 0)
    {
        int lastOne = check_card % 10;
        sum = sum + lastOne;
        check_card = check_card / 100;
    }

    check_card = card / 10;
    while (check_card > 0)
    {
        int lastOne = check_card % 10;
        int doubleOne = lastOne * 2;
        sum = sum + (doubleOne % 10) + (doubleOne / 10);
        check_card = check_card / 100;
    }

    check_card = card;
    while (check_card != 0)
    {
        check_card = check_card / 10;
        count++;
    }

    for (int i = 0; i < count - 2; i++)
    {
        divider = divider * 10;
    }

    int firstOne = card / divider, 
        firstTwo = card / (divider / 10);


    if (sum % 10 == 0)
    {
        if (firstOne == 4 && (count == 13 || count == 16))
        {
            printf("VISA");
        }
        else if ((firstTwo == 34 || firstTwo == 37) && count == 15)
        {
            printf("AMEX");
        }
        else if ((firstTwo > 50 && firstTwo < 56) && count == 16)
        {
            printf("MASTERCARD");
        }
        else 
        {
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }

}