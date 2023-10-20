#include "jpeg_entropy_encoder.h"
#include <stdio.h>

#define PIXEL_LINE 8
#define PIXEL_BLOCK PIXEL_LINE * PIXEL_LINE

unsigned char coefficients[PIXEL_BLOCK];

void fill_coefficients() {
    for(int i = 0;i < PIXEL_BLOCK;i++)
        coefficients[i] = i;
}

void print_coefficients() {
    for(int i = 0;i < PIXEL_BLOCK;i++) {
        if(i % PIXEL_LINE == 0)
            printf("\n");
        
        printf("%2d ", coefficients[i]);
    }
    printf("\n\n");
}