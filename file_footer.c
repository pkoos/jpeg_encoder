#include "file_footer.h"

void get_file_footer(FILE * file, unsigned char * location ) {
    fseek(file, 0, SEEK_END);
    fseek(file, -2, SEEK_CUR);
    fread(location, 1, 2, file);
}

void print_file_footer(unsigned char * footer) {
    printf("file footer: %x %x\n", footer[0], footer[1]);
}