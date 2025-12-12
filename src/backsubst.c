#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {


	// r to liczba wierszy
	// c to liczba kolumn

	int n = mat->r;

	// musi byc kwadratowa
	if (mat->r != mat->c || mat->r != b->r || b->c != 1 || x->r != b->r || x->c != 1) {
		return 2;
	}

	for(int i = n-1; i >= 0; i--) {
		// dzielenie przez 0
		if (mat->data[i][i] == 0) {
			return 1;
		}

		// obliczanie
		x->data[i][0] = b->data[i][0];
		for(int j = i + 1; j < n; j++) {
			x->data[i][0] -= mat->data[i][j] * x->data[j][0];
		}
		x->data[i][0] /= mat->data[i][i];
	}

	return 0;
}
