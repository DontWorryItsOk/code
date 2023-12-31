#include <stdio.h>
int main() {
    int arr [100]; // от 0 до 99
    int i;
    for(i = 0; i < 100; i++) {
        arr[i] = i;
    }
    
    for(i = 0; i < 100; i++) {
    printf("%d, ", arr[i]);
}
printf("\n");
}
