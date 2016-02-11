#include <stdio.h>
#include <stdlib.h>

#include "timer.h"
#include "Lab3IO.h"

// Global Variables
double **A;
double *x;
int    size;

// Function Signatures
void gaussian_elimination();
void jordan_elimination();
void pivot_rows();
void swap_rows();

int main(int argc, char* argv[]) {

    Lab3LoadInput(&A, &size);
    x = CreateVec(size);

    gaussian_elimination();
    jordan_elimination();

    DestroyVec(x);
    DestroyMat(A, size);
    return EXIT_SUCCESS;
}

void gaussian_elimination() {
    pivot_rows();
}

void jordan_elimination() {

}

void pivot_rows() {
    int cur_col, cur_row, max_row;

    for (cur_col = 0; cur_col < size; ++cur_col) {
        cur_row = cur_col;
        max_row = cur_row;

        for( ; cur_row < size; ++cur_row) {
            if (A[cur_row][cur_col] > A[max_row][cur_col])
                max_row = cur_row;
        }

        swap_rows(cur_row, max_row);
    }
}

void swap_rows(int row1, int row2) {
    
}
