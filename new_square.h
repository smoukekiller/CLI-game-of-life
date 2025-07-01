#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "millis.h"


bool *init_array(int rows, int columns);
void print_board(bool *arr_ptr, int row, int col);
void fill_random(bool *arr_ptr, int row, int col);
int find_neighbours(bool *arr_ptr, int order, int row, int col);
void render_new(bool *arr_ptr, bool *help_arr_ptr, int row, int col);

