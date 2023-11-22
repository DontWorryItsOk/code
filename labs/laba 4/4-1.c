#include <stdio.h>

int dayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    
    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;

    int h = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // Преобразуем значение h в день недели (0 - воскресенье, 1 - понедельник, и так далее)
    int dayOfWeek = (h + 5) % 7;

    return dayOfWeek;
}

int electionDay(int year) {
    // Выборы назначаются на первый вторник после первого понедельника ноября
    int novemberDay = dayOfWeek(year, 11, 1);

    // Если 1 ноября выпадает на воскресенье, выбираем второй ноября
    if (novemberDay == 0) {
        novemberDay = dayOfWeek(year, 11, 2);
    }

    // Определяем день первого понедельника в ноябре
    int firstMonday = (8 - novemberDay) % 7 + 1;

    // Выборы назначаются на первый вторник после первого понедельника ноября
    int electionDay = firstMonday ;

    return electionDay;
}

int main() {
    int year;
    printf("Введите год: ");
    scanf("%d", &year);

    int electionDayOfMonth = electionDay(year);

    printf("Выборы в %d году назначены на первый вторник после первого понедельника ноября и выпадут на %d ноября.\n", year, electionDayOfMonth);

    return 0;
}
