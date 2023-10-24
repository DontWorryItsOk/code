/* Цель при игре в боулинг – сбить шаром максимальное количество кеглей. 
Партия в этой игре состоит из 10 туров. Задача игрока – сбить все 10 кеглей в 
каждом туре. Для этого игрок может совершить 2 броска шара, за исключением:

если 10 кеглей сбиты первым броском, то второй бросок не совершается;
если 10 кеглей сбиты первым броском в десятом туре, то игроку 
предоставляются два призовых броска, а если двумя бросками – один.

Количество очков в каждом туре равно количеству сбитых кеглей, кроме двух 
бросков, называемых «Strike» и «Spare».

Strike: игрок сбивает 10 кеглей первым броском, очки в этом туре начисляются 
из расчета – 10 + сумма очков за два последующих броска.

Spare: игрок сбивает 10 кеглей двумя бросками, очки в этом туре начисляются 
из расчета – 10 + сумма очков за один последующий бросок.

Результат партии складывается из результатов всех 10 туров.
Требуется описать функцию, которая по заданным количеству бросков и очков 
в каждом броске определит количество набранных игроком очков */

// 10 туров по 2 броска

// пусть мне дали кол-во бросков и по скольку очков за бросок каждый чел получил, я считаю общую сумму учитывая правила

#include <stdio.h>
#include <stdlib.h>

int throw[100], i;

void bowling() {
int tour, strike = 0, spare = 0, now = 0, score = 0; // now - бросок сейчас(начиная с 0, т.к. элементы массива)
for (tour = 1; tour <= 10; tour++) { // тур, начиная с 1

if(i <= 21) { // если 2 броска в туре не больше 10 и бросков не больше 21

if(throw[now] == 10) { // strike
    score += throw[now] + throw[now+1] + throw[now+2];
    now++; // сделан 1 бросок 
    // при сравнении 1 и 2 элемента throw(2 и 3 бросков) они могут быть 20, если это 2 страйка подряд!!!!!!!!!
}

else if(throw[now] + throw[now+1] == 10) { // spare
    score += 10 + throw[now+2];
    now += 2; // сделано 2 броска
}

else if(throw[now]+throw[now+1] < 10) { // average boy
    score += throw[now] + throw[now+1];
    now += 2; // сделано 2 броска
}
else if(throw[now] > 10) {
    printf("\nВы ввели неправильные значения1!");
    exit(0);
}
printf("\nВсего очков после тура %d=%d", tour, score); // строка для проверки, можно удалить
}

else {
    printf("\nВы ввели неправильные значения2!");
    exit(0);
}

}

if (((strike % 2 == 0) && (i % 2 == 0)) || ((strike % 2 != 0) && (i % 2 != 0)))
    printf("\nСумма очков равна %d", score);
else {
    printf("\nВы ввели неправильные значения!!!");
    exit(0);
}
}


int main() {
int N;  
printf("Введите количество бросков: ");
scanf("%d", &N);

for (i = 0; i < N; i++) {
    printf("Введите кол-во очков в %d броске: ", i + 1);
    scanf("%d", &throw[i]);
}

bowling();
return 0;
/* варианты для проверки:
10 10 10 3 4 6 2 1 6 8 1 6 1 2 4 4 4(17 бросков) = 122(верно)
10 10 10 0 0 6 2 1 6 8 1 6 1 2 4 4 4(17 бросков) = 105(верно)
10 10 10 0 4 6 2 0 6 8 1 6 1 2 4 4 0(17 бросков) = 108(верно) 
10 10 10 0 4 6 2 0 6 8 1 6 1 2 4 10 3 5(18 бросков) = 122(верно) - страйк в 10 туре
10 10 10 0 4 6 2 0 6 8 1 6 1 2 4 7 3 5(18 бросков) = 119(верно) - спейр в 10 туре
6 4 2 5 3 6 8 1 2 1 7 2 6 2 5 4 1 7 6 4 5(21 бросок) = 89(верно) - спейр + спейр в 10 туре
*/
}