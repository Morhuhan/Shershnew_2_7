//main.exe from.txt /A to.txt  - для текстовых
//main.exe from.jpg /B to.jpg  - для всех

#include <stdio.h>
#include <stdlib.h>

void copy (FILE* from, FILE* to) {

    char ch;

    int size;

    fseek(from, 0, SEEK_END);
    size = ftell(from);
    fseek(from, 0, SEEK_SET);

    printf("size = %d", size);

    for (int i = 0; i < size; i++) {
        ch=getc(from);
        putc(ch,to);
    }
}


void main(int argc, char* argv[]) {

    FILE* from;
    FILE* to;

    if (fopen(argv[3], "r") != NULL) {
        printf("File with this name already exists!");
        exit(0);
    }

    if (strcmp(argv[2], "/A") == 0) {

        from = fopen(argv[1], "r");
        to = fopen(argv[3], "w");

        if (from == NULL) {
            printf("Directory 1 does not exist");
            exit(0);
        }

        if (to == NULL) {
            printf("Directory 2 does not exist");
            exit(0);
        }
    }

    else if (strcmp(argv[2], "/B") == 0) {

        from = fopen(argv[1], "rb");
        to = fopen(argv[3], "wb");

        if (fopen(argv[1], "rb") == NULL) {
            printf("Directory 1 does not exist");
            exit(0);
        }

        if (fopen(argv[3], "wb") == NULL) {
            printf("Directory 2 does not exist");
            exit(0);
        }
    }

    else {
        printf("Uncorrect argument #2");
        exit(0);
    }

    copy(from, to);

    fclose(from);
    fclose(to);
}