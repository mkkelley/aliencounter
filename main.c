#include <stdio.h>

#define GRID_SIZE 10
#define OUTFILE "numbers.txt"

typedef unsigned int uint;

typedef enum estate_t {ZERO, ONE, TWO} state_t;

typedef struct turmite {
    uint grid[GRID_SIZE][GRID_SIZE];
    uint x;
    uint y;
    state_t state;
} turmite_t;

int tick(turmite_t*);
void display(FILE*, turmite_t*);


int main() {

    FILE* f = fopen(OUTFILE, "w");

    turmite_t t = {
            .x = 1,
            .y = 1,
            .state = ZERO,
            .grid = {0},
    };

    uint gencount = 0;
    for (; gencount < 100;) {
        int gen = tick(&t);
        if (gen == 1) {
            fprintf(f, "\n%d\n\n", gencount++);
            display(f, &t);
        }
    }

    return 0;
}

int tick(turmite_t* t) {
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

void display(FILE*f, turmite_t* t) {
    for (int i = GRID_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < GRID_SIZE; j++) {
            fprintf(f, "%d", t->grid[j][i]);
        }
        fprintf(f, "\n");
    }
}