//
// Created by Michael Kelley on 4/18/2017.
//

#include <stdlib.h>
#include <math.h>
#include "analysis.h"

uint popcount(termite_t* t) {
    uint count = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (t->grid[i][j] == 1) {
                ++count;
            }
        }
    }
    return count;
}

unsigned long bin_to_num(termite_t* t) {
    uint buffer_size = (GRID_SIZE - 2) * (GRID_SIZE - 6);
    char buffer[buffer_size + 1];
    for (int i = 0; i < buffer_size + 1; i++) {
        buffer[i] = '0';
    }

    buffer[buffer_size] = '\0';
    //uint pos = buffer_size - 1;
    uint pos = 0;
    for (int i = GRID_SIZE - 1; i >= 2; i--) {
        for (int j = GRID_SIZE - 6; j > 0; j--) {
            buffer[pos++] = (char) (t->grid[j][i] + 48);
        }
    }
    return strtoul(buffer, NULL, 2);
}

uint* rowsums(termite_t* t) {
    uint* sums = malloc(GRID_SIZE * sizeof(uint));
    for (int i = 0; i < GRID_SIZE; i++) {
        uint sum = 0;
        for (int j = 0; j < GRID_SIZE; j++) {
            sum += t->grid[j][i];
        }
        sums[i] = sum;
    }
    return sums;
}

uint** sqmatmult(uint** a, uint** b, uint size) {
    uint** out = malloc(size * size * sizeof(uint));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            out[i][j] = a[i][j] * b[i][j];
        }
    }
    return out;
}

uint sqmatsum(uint** a, uint size) {
    uint sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

