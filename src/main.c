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
int  get_max_row();
void swap_rows();

int main(int argc, char* argv[]) {

    Lab3LoadInput(&A, &size);
    x = CreateVec(size);

    PrintMat(A, size, size + 1);

    printf("\n");

    gaussian_elimination();

    PrintMat(A, size, size + 1);
    printf("\n");
    jordan_elimination();

    PrintMat(A, size, size + 1);

    DestroyVec(x);
    DestroyMat(A, size);
    return EXIT_SUCCESS;
}

void gaussian_elimination() {
    int i, j, k;

    for(k = 0; k < size - 1; ++k) {
        swap_rows(k, get_max_row(k));

        for(i = k + 1; i < size; ++i) {
            double temp = A[i][k] / A[k][k];

            for(j = k; j < size + 1; ++j) {
                A[i][j] = A[i][j] - temp * A[k][j];
            }
        }
    }
}

void jordan_elimination() {
    int i, k;

    for (k = size-1 ; k > 0; --k) {
        for (i = 0; i < k; ++i) {
            A[i][size] = A[i][size] - (A[i][k] / A[k][k] * A[k][size]);
            A[i][k] = 0;
        }
    }
}

int get_max_row(int cur_row) {
    int cur_col = cur_row;
    int max_row = cur_row;

    for( ; cur_row < size; ++cur_row) {
        if (A[cur_row][cur_col] > A[max_row][cur_col])
            max_row = cur_row;
    }

    return max_row;
}

void swap_rows(int row1, int row2) {
    double* temp = A[row1];
    A[row1] = A[row2];
    A[row2] = temp;
}
