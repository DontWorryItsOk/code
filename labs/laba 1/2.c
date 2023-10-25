#include <stdio.h>
#include <math.h>
int main()
{int мм, см, м, tmp;
printf("Введите мм:\n");
scanf("%d", &мм);
tmp=м;
м= мм / 1000;
tmp= мм - м*1000;
см= мм /10- м*100;
мм= tmp-см*10;
printf("%d метры %d сантиметры %d мм", м, см,мм);
return 0;
}