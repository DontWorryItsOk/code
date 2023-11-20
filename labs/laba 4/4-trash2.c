#include <stdio.h>

// Функция для определения дня выборов
int dayOfElection(int year) {
    // 1 января 2001 года был понедельник (день недели 0)
    int dayOfWeek = 0;

    // Шагаем по годам от 2001 до заданного года
    for (int currentYear = 2001; currentYear < year; currentYear++) {
        // Високосный год
        if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) {
            // Добавляем 366 дней в високосном году
            dayOfWeek = (dayOfWeek + 366) % 7;
        } else {
            // Добавляем 365 дней в обычном году
            dayOfWeek = (dayOfWeek + 365) % 7;
        }
    }

    // Возвращаем номер дня недели для первого понедельника ноября выбранного года
    // (выборы на первый вторник после первого понедельника ноября)
    return (dayOfWeek + 306) % 7;
}

int main() {
    int year;

    // Вводим год
    printf("Введите год: ");
    scanf("%d", &year);

    // Проверяем валидность года
    if (year >= 2001) {
        // Вызываем функцию для определения дня выборов
        int electionDay = dayOfElection(year);

        // Выводим результат
        printf("Выборы в %d году будут во вторник, %d ноября.\n", year, electionDay + 1);
    } else {
        // Выводим сообщение об ошибке
        printf("Пожалуйста, введите год, начиная с 2001.\n");
    }

    return 0;
}