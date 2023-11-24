#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void des_to_dvoichn(int des) {
    int arr[50];
    int i = 0;

    while (des > 0) {
        arr[i] = des % 2;
        des = des / 2;
        i++;
    }

    for(int j = i-1; j >=0; j--) {
        printf("%d", arr[j]);
    }
}

int main() {
    int chislo;
    printf("vvedi ");
    scanf("%d", &chislo);
    des_to_dvoichn(chislo);
}