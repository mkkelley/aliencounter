//
// Created by Michael Kelley on 4/18/2017.
//

#include "termite.h"

int tick(termite_t* t) {
    uint current_color = t->grid[t->x][t->y];
    uint* current_cell = &t->grid[t->x][t->y];
    switch (t->state) {
        case ZERO:
            if (current_color == 0) {
                *current_cell = 0;
                ++t->y;
                t->state = TWO;
            } else {
                *current_cell = 1;
                --t->y;
                t->state = ONE;
            }
            break;
        case ONE:
            if (current_color == 0) {
                *current_cell = 0;
                ++t->x;
                t->state = ZERO;
            } else {
                *current_cell = 0;
                --t->y;
                t->state = ZERO;
            }
            break;
        case TWO:
            if (current_color == 0) {
                *current_cell = 1;
                --t->x;
                t->state = ONE;
            } else {
                *current_cell = 1;
                ++t->y;
                t->state = TWO;
            }
            break;
    }
    if (t->x == 1 && t->y == 1) {
        return 1;
    } else {
        return 0;
    }
}

void display(FILE*f, termite_t* t) {
    for (int i = GRID_SIZE - 1; i >= 2; i--) {
        for (int j = GRID_SIZE - 6; j > 0; j--) {
            fprintf(f, "%d", t->grid[j][i]);
        }
    }
}
