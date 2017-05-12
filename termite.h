//
// Created by Michael Kelley on 4/18/2017.
//

#pragma once
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 50

typedef unsigned int uint;

typedef enum estate_t {ZERO, ONE, TWO} state_t;

typedef struct termite {
    uint grid[GRID_SIZE][GRID_SIZE];
    uint x;
    uint y;
    state_t state;
} termite_t;

int tick(termite_t*);
void display(FILE*, termite_t*,bool);
