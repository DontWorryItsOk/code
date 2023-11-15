#include <stdio.h>
int main() {
    
    int s, Katya, Petya, Sergey;
    printf("Введите количество журавликов: ");
    scanf("%d", &s);
    int i = s / 6;;
    Sergey = i;
    Petya = i;
    Katya = 2 * (Petya + Sergey);
   
    
    printf("Катя сделала %d журавликов\n", Katya);
    printf("Петя сделал %d журавликов\n", Petya);
    printf("Сережа сделал %d журавликов\n", Sergey);

return 0;
}
