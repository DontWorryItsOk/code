#include <stdio.h>
int main() {
    int ar [100]; // от 0 до 99
    int i;
    for(i = 0; i < 100; i++) {
        ar[i] = i;
    }
    
    for(i = 0; i < 100; i++) {
    printf("%d, ", ar[i]);
}
printf("\n");
}
