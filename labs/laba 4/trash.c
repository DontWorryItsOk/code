#include <stdio.h>

// Функция для определения, является ли год високосным
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для определения даты первого вторника ноября для заданного года
void electionDate(int year, int *day, int *month) {
    // 1 января 2001 года - понедельник
    *day = 1; // 1 января
    *month = 1; // Январь

    // Определение дня недели для 1.1.года
    int dayOfWeek = (1 + 2 * (13 * (*month + 1) / 5) + (year - 1) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;

    // Перевод к первому понедельнику ноября
    while (*month < 11 || dayOfWeek != 1) {
        // Переход к следующему дню
        (*day)++;
        dayOfWeek = (dayOfWeek + 1) % 7;

        // Учитываем високосные года
        if (*month == 2) {
            if (isLeapYear(year)) {
                if (*day > 29) {
                    *day = 1;
                    (*month)++;
                }
            } else {
                if (*day > 28) {
                    *day = 1;
                    (*month)++;
                }
            }
        } else if (*day > 30 || (*month == 4 || *month == 6 || *month == 9 || *month == 11)) {
            *day = 1;
            (*month)++;
        }
    }

    // Перевод ко вторнику
    (*day) += (9 - dayOfWeek + 7) % 7;
}

int main() {
    int year, day, month;

    printf("Введите год: ");
    scanf("%d", &year);

    electionDate(year, &day, &month);

    printf("Выборы в %d году будут в первый вторник ноября: %d ноября.\n", year, day);

    return 0;
}
