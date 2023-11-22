#include <stdio.h>

// Функция для определения дня недели по алгоритму Зеллера
int getDayOfWeek(int year) 
{
    int day, month, k, q, m, j;

    day = 1;
    month = 11; // Ноябрь
    k = year % 100;
    q = 1;
    m = month;
    j = year / 100;

    // Формула Зеллера
    int dayOfWeek = (day + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    // Значение dayOfWeek будет от 0 (суббота) до 6 (пятница)
    // Мы хотим, чтобы 0 соответствовало воскресенью, поэтому сдвигаем результат на 1
    return (dayOfWeek + 5) % 7 + 1;
}

// Функция для определения дня выборов
int getElectionDay(int year) 
{
    // Определяем первый понедельник ноября в заданном году
    int firstMonday = 1 + (8 - getDayOfWeek(year)) % 7;

    // Выборы назначают на первый вторник после первого понедельника ноября
    int electionDay = firstMonday + 1;

    return electionDay;
}

int main() 
{
    int year;

    // Ввод года
    printf("Введите год: ");
    scanf("%d", &year);

    // Получаем день выборов
    int electionDay = getElectionDay(year);

    // Вывод результата
    printf("Выборы в %d году будут во вторник, %d ноября.\n", year, electionDay);

    return 0;
}
