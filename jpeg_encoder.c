#include <stdio.h>
#include <stdbool.h>
#include "file_header.h"
#include "file_footer.h"
#include "jpeg_entropy_encoder.h"

#define DEBUG false
#define TEST_FILE_PATH "./files/profile_pic.jpg"

int main(void) {
    FILE* jpeg_file;
    unsigned char file_header[2] = {0};
    unsigned char file_footer[2] = {0};

    jpeg_file = fopen(TEST_FILE_PATH, "rb");
    if(jpeg_file == NULL) {
        perror("fopen");
    }

    if(DEBUG)
        printf("File has been opened.\n");
    
    get_file_header(jpeg_file, file_header);

    if(DEBUG) {
        print_file_header(file_header);
    }
    
    get_file_footer(jpeg_file, file_footer);

    if(DEBUG) {
        print_file_footer(file_footer);
    }

    fill_coefficients();
    // print_coefficients();

    zig_zag_coefficients();

    fclose(jpeg_file);
}

