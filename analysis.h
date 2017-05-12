//
// Created by Michael Kelley on 4/18/2017.
//

#pragma once

#include "termite.h"

/**
 * Count the number of active (colored) cells in the termite grid.
 */
uint popcount(termite_t*);

unsigned long bin_to_num(termite_t*);

uint* rowsums(termite_t* t);

uint** sqmatmult(uint**,uint**,uint);

uint sqmatsum(uint**, uint);
