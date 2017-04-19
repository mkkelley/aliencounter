//
// Created by Michael Kelley on 4/18/2017.
//

#pragma once
#include <stdio.h>

#define GRID_SIZE 10

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
