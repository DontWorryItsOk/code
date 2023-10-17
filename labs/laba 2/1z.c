#include <stdio.h>
#include <math.h>
int main()
{
int a, b, c, g, f, t;
printf("Number 1: \n");
scanf("%d", &a);
printf("Number 2: \n");
scanf("%d", &b);
printf("Number 3: \n");
scanf("%d", &c);
g=a+b;
f=b+c;
t=a+c;
if (g>t)
{
printf("Максимальные числа a b, их сумма: %d", g);
} 
else
{
if (f>g)
{
printf("Максимальные числа b c, их сумма: %d", f);
}
else
{
    if (t>f)
{
printf("Максимальные числа a c, их сумма: %d", t);
}
}
}
}