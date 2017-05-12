#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "analysis.h"
#include "termite.h"

#define OUTFILE "numbers.txt"
#define POINTFILE "plot.txt"

void gen_points(int n, termite_t* t) {
    FILE* f = fopen(POINTFILE, "w");
    for (int i = 1; i <= n;) {
        int gen = tick(t);
        if (gen == 1) {
        }
    }
}

int main(int argc, char** argv) {

    termite_t t = {
            .x = 1,
            .y = 1,
            .state = ZERO,
            .grid = {0},
    };

    if (argc > 1) {
        int n = atoi(argv[1]);
        gen_points(n, &t);
        return 0;
    }

    FILE* f = fopen(OUTFILE, "w");
    fprintf(f, "%d %d", GRID_SIZE - 30, GRID_SIZE - 30);

    uint gencount = 1;
//    for (; gencount < 1000000000; gencount++) {
    for(;gencount <= 10000;) {
        int gen = tick(&t);
        if (gen == 1) {
            fprintf(f, "\n\n%d\n\n", gencount++);
//            fprintf(f, "%d %d ", gencount++, popcount(&t));
//            uint* row_sums = rowsums(&t);
//            for (int i = 0; i < GRID_SIZE; i++) {
//                fprintf(f, "%d ", row_sums[i]);
//            }
            display(f, &t, true);
            fprintf(f, "\n");
        }
    }
    display(stdout, &t, false);

    return 0;
}

