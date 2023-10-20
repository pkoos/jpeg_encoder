#ifndef JPEG_ENTROPY_ENCODER_H_
#define JPEG_ENTROPY_ENCODER_H_

void fill_coefficients(void);
void print_coefficients(void);
void zig_zag_coefficients(void);

int down(int);
int right(int);
int down_left(int);
int up_right(int);

void lap_loop(int laps, int * working_index, int * index_counter, int function(int));

#endif
