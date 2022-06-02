#include <stdio.h>
#include <stdlib.h>

//Копирует все символы из файла from в to
void copy (FILE* from, FILE* to) {

    char ch;

    while((ch=getc(from))!=EOF) {
        putc(ch,to);
    }

}


void main(int argc, char* argv[]) {

    FILE* from;
    FILE* to;

    if (strcmp(argv[2], "/A") == 0) {
        from = fopen(argv[1], "r");
        to = fopen(argv[3], "w");
        printf("ok!");
    }

    else if (strcmp(argv[2], "/B") == 0) {
        from = fopen(argv[1], "rb");
        to = fopen(argv[3], "wb");
    }

    else {
        printf("Uncorrect argument #2");
        exit(0);
    }

    copy(from, to);

    fclose(from);
    fclose(to);
}