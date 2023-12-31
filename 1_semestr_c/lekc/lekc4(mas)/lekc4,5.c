#include <stdio.h>
int main() {
    int mas[1000];
    int N;
    int s, p;
    printf("Введите кол-во: ");
    scanf("%d", &N);
    for(int i = 0; i<N; i++) {
        printf("mas[%d]= ", i);
        scanf("%d", &mas[i]);
    }
    s = 0;
    p = 1;
    int min, max;
    min = mas[0];
    max = mas[0];
    for(int i = 0; i < N; i++) {
        s += mas[i];
        p *= mas[i];
        if (mas[i] < min) {
            min = mas[i];
        }
        if (mas[i]>max)
        {
            max = mas[i];
        }
    }
    return 0;
}
