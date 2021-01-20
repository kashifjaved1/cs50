#include <stdio.h>

int main()
{
    int start, end, year = 0, gain, lose;

    do
    {
        printf("Enter Start Size: ");
        scanf("%i", &start);
    }
    while (start < 9);
    
    do
    {
        printf("Enter Start Size: ");
        scanf("%i", &end);
    }
    while (end < start);
    
    while(start < end){
        
        gain = start / 3;
        lose = start / 4;
        gain = gain - lose;
        start = start + gain;
        year++;
        
    }
    
    printf("Years: %i", year);
}