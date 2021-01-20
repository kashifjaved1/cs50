#include <stdio.h>
int main() {
   int height;
   printf("Enter the height: ");
   scanf("%d", &height);
   for (int i = 1; i <= height; i++) {
        for (int space = height - i; space > 0; space--) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
   return 0;
}