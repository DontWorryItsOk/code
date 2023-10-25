#include<stdio.h>
int main()
{
    int DZ,n0,n1;
    printf("Введите кол-во домашних заданий (до 99): ");
    scanf("%d",&DZ);
    if (DZ >= 10 && DZ <= 20)
    {
        switch(DZ)
        {
            case 10: printf("десять домашних заданий");
                break;
            case 11: printf("одиннадцать домашних заданий");
                break;
            case 12: printf("двенадцать домашних заданий");
                break;
            case 13: printf("тринадцать домашних заданий");
                break;
            case 14: printf("четырнадцать домашних заданий");
                break;
            case 15: printf("пятнадцать домашних заданий");
                break;
            case 16: printf("шестнадцать домашних заданий");
                break;
            case 17: printf("семнадцать домашних заданий");
                break;
            case 18: printf("восемнадцать домашних заданий");
                break;
            case 19: printf("девятнадцать домашних заданий");
                break;
            default: break;
        }
    }
    if ((DZ > 0 && DZ < 10) || (DZ > 20 && DZ <= 99))
    {
        n1=DZ/10;
        n0=DZ%10;
        switch(n1)
        {
            case 2: printf("двадцать ");
                break;
            case 3: printf("тридцать ");
                break;
            case 4: printf("сорок ");
                break;
            case 5: printf("пятьдесят ");
                break;
            case 6: printf("шестьдесят ");
                break;
            case 7: printf("семьдесят ");
                break;
            case 8: printf("восемьдесят ");
                break;
            case 9: printf("девяносто ");
                break;
            default: break;
        }
        switch(n0)
        {
            case 0: printf("домашних заданий");
                break;
            case 1: printf("одно домашнее задание");
                break;
            case 2: printf("два домашних задания");
                break;
            case 3: printf("три домашних задания");
                break;
            case 4: printf("четыре домашних заданий");
                break;
            case 5: printf("пять домашних заданий");
                break;
            case 6: printf("шесть домашних заданий");
                break;
            case 7: printf("семь домашних заданий");
                break;
            case 8: printf("восемь домашних заданий");
                break;
            case 9: printf("девять домашних заданий");
                break;
            default: break;
        }
    }
    if ((DZ < 0) || (DZ > 99)) printf("null");    
    return 0;
}