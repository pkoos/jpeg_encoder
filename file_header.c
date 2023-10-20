#include "file_header.h"

void get_file_header(FILE * file, unsigned char * location) {
    rewind(file);
    fread(location, 1, 2, file);
}

void print_file_header(unsigned char * header) {
        printf("file header: %x %x\n", header[0], header[1]);
}