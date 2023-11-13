#include <stdio.h>
int main() {
    float n, p;
    
    printf("Введите кол-во процессоров n: ");
    scanf("%f", &n);
    printf("Введите процент вычислений p: ");
    scanf("%f", &p);

    float perv = (1 - p/100) * 1/n;
    float vtor = (p/100);
    float all = perv + vtor;
    float uskorenie = 1 / all;
    printf("Ускорение по сравнению с одним процессором составит %f", uskorenie);
    
    return 0;

}
