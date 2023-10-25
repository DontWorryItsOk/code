#include <stdio.h>
#define PI 3.14159265
int main()
{
    float градусы, радианы;
    printf("Введите градусы:\n");
    scanf("%f", &градусы);
    радианы = градусы * (PI / 180.0);
    printf("%f градусы = %f радианы\n", градусы, радианы);
    return 0;
}
// comment 1