#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in, *out;
    char ch;
    if(argc != 3) {
        printf("Непр. кол-во арг.");
        exit(1);
    }
    
    if ((in=fopen(argv[1], "rb")) == NULL) {
        printf("Невозм. открыть in файл");
        exit(1);
    }

    if(out=fopen(argv[2], "wb") == NULL) {
        printf("Невозм. открыть файл");
        exit(1);
    }

    while (!feof(in)) {
        ch = getc(in);
        if(!feof(in))putc(ch,out);
    }
    fclose(out);
    fclose(in);
    return 0;
}

void rewind(FILE *fp) {
}