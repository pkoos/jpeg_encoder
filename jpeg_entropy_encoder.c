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
    int lap = 0;
    int increment = 1;

    // printf("lap: %d\n", lap);
    zig_zag_path[index_counter++] = working_index;
    printf("%d: %d\n", index_counter, working_index);
    
    /*
        Lap 1
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, down_left);


    /*
        Lap 2
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, down, up_right);

    /*
        Lap 3
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, down_left);

    /*
        Lap 4
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, down, up_right);

    /*
        Lap 5
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, down_left);

    /*
        Lap 6
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, down, up_right);

    /*
        Lap 7
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, down_left);

    increment = -1;

    /*
        Lap 8
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, up_right);

    /*
        Lap 9
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, down, down_left);

    /*
        Lap 10
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, up_right);

    /*
        Lap 11
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, down, down_left);

    /*
        Lap 12
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, right, up_right);

    /*
        Lap 13
    */
    lap+= increment;
    lap_loop(lap, &working_index, &index_counter, down, down_left);

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
