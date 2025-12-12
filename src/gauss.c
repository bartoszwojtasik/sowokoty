#include "gauss.h"
#include <math.h>

int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r;

    if (mat->r != mat->c) return 1;
    if (mat->r != b->r) return 1;

    for (int k = 0; k < n - 1; k++) {
        int max_row = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])) {
                max_row = i;
            }
        }

        if (fabs(mat->data[max_row][k]) < 1e-12) {
            return 1;
        }

        if (max_row != k) {
            double *temp = mat->data[k];
            mat->data[k] = mat->data[max_row];
            mat->data[max_row] = temp;

            double *temp_b = b->data[k];
            b->data[k] = b->data[max_row];
            b->data[max_row] = temp_b;
        }

        for (int i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];

            for (int j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    if (fabs(mat->data[n-1][n-1]) < 1e-12) return 1;

    return 0;
}
