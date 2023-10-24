#include <stdio.h>
void reverse(int number) {
while(number) {
printf("%d", number%10);
number /= 10;
}
}

 int main() {
    int x;
    printf("Введите число: ", &x);
    scanf("%d", &x);
    reverse(x);
    printf("\n");
    reverse(12345);
    printf("\n");
    reverse(x);
    
    return 0;

 }