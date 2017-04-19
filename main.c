#include <stdio.h>

#include "termite.h"

#define OUTFILE "numbers.txt"



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

