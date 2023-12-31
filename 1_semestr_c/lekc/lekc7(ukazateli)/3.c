#include <stdio.h>
#include <stdlib.h>
int search(char *p, char name) {
    int t;
    for(t=0; *(p+t); t++) {
        if(*(p+t) == name) {
            return t;
        }
    }
    return -1;
}

int main() {
    char *p = (char*)malloc(27 * sizeof(char));
    int t;
    for(t = 0; t<26; t++)
    {
        *(p+t) = 'a';
    }
    *(p+t) = '\0';
    *(p+10) = 'f';
    printf("position = %d", search(p,t));
    return 0;
}