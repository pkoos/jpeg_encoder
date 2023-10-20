#include "jpeg_entropy_encoder.h"
#include <stdio.h>
#include <stdbool.h>

#define PIXEL_LINE 8
#define PIXEL_BLOCK PIXEL_LINE * PIXEL_LINE

unsigned char coefficients[PIXEL_BLOCK] = { 0 };
unsigned char zig_zag_path[PIXEL_BLOCK] = { 0 };

void fill_coefficients(void) {
    for(int i = 0; i < PIXEL_BLOCK; i++)
        coefficients[i] = i;
}

void print_coefficients(void) {
    for(int i = 0; i < PIXEL_BLOCK; i++) {
        if(i % PIXEL_LINE == 0)
            printf("\n");
        
        printf("%2d ", coefficients[i]);
    }
    printf("\n\n");
}

void zig_zag_coefficients(void) {

    int index_counter = 0;
    int working_index = 0;

    zig_zag_path[index_counter++] = working_index;
    printf("%d: %d\n", index_counter, working_index);
    
    for(int i = 1;i < 8; i++) {
        if (i % 2 == 1)
            lap_loop(i, &working_index, &index_counter, right, down_left);
        else
            lap_loop(i, &working_index, &index_counter, down, up_right);

    }

    for(int i = 6; i > 0; --i) {
        if(i % 2 == 0) {
            lap_loop(i, &working_index, &index_counter, right, up_right);
        } else {
            lap_loop(i, &working_index, &index_counter, down, down_left);
        }
    }

    working_index = right(working_index);
    zig_zag_path[index_counter++] = working_index;
    printf("%d: %d\n", index_counter, working_index);

}

int down(int index) {
    return index + 8;
}

int right(int index) {
    return index + 1;
}

int down_left(int index) {
    return index + 7;
}

int up_right(int index) {
    return index - 7;
}

void lap_loop(int laps, int * working_index, int * index_counter, int single_function(int), int loop_function(int)) {
    * working_index = single_function(* working_index);
    * index_counter = * index_counter + 1;
    zig_zag_path[* index_counter] = * working_index;
    printf("%d: %d\n", * index_counter, * working_index);
    for(int i = 0; i < laps; i++) {
        *working_index = loop_function(*working_index);
        *index_counter = *index_counter + 1;
        zig_zag_path[*index_counter] = *working_index;
        printf("%d: %d\n", *index_counter, *working_index);
    }
}
