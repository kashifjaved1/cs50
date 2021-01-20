#include <stdio.h>
#include <math.h>

int main(){
    int pennies, quarter = 25, dime = 10, nickel = 5, peny = 1, coins = 0;
    float money;

    printf("Enter your Ammount: ");
    scanf("%f", &money);

    pennies = round(money * 100);

    do{
        if(pennies >= quarter){
            pennies = pennies - quarter;
            coins++;
        }
        else if(pennies >= dime){
            pennies = pennies - dime;
            coins++;
        }
        else if(pennies >= nickel){
            pennies = pennies - nickel;
            coins++;
        }
        else if(pennies >= peny){
            pennies = pennies - peny;
            coins++;
        }
        //end:
    }
    while(pennies > 0);

    printf("%i", coins);

}