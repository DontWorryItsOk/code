#include <stdio.h>
#include <math.h>
int main()
{
int a, b, c, x;
printf("Number 1: \n");
scanf("%d", &a);
printf("Number 2: \n");
scanf("%d", &b);
printf("Number 3: \n");
scanf("%d", &c);
if (a>=b)
{
    if (b>c)
    {
            x=a+b;
    }
        else
        {
            x=a+c;
        }   
}
    if (b>=c)
    {
        if (c>a)
        {
            x=b+c;
        }
        else 
        {
            x=b+a;
        }
    }
    if (c>=a)
    {
        if (a>b)
        {
            x=c+a;
        }
        else
        {
            x=c+b;
        }
    }
    printf("result= %d",x);
    return 0;
}