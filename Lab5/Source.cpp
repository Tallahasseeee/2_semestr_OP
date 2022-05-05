#include "Header.h"

TMatrix::TMatrix() {}

//int TMatrix::Sum() { return 0; }
int** TMatrix::get_matrix() { return Matrix; }

int TMatrix::get_size() { return size; }

DoubleMatrix::DoubleMatrix() {
	size = 2;
	Matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		Matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			Matrix[i][j] = rand() % 20 - 10;
		}
	}
}

TripleMatrix::TripleMatrix() {
	size = 3;
	Matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		Matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			Matrix[i][j] = rand() % 20 - 10;
		}
	}
}

int TMatrix::Sum() {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum += Matrix[i][j];
		}
	}
	return sum;
}
 

int DoubleMatrix::determinant(){
	return Matrix[0][0] * Matrix[1][1] - Matrix[1][0] * Matrix[0][1];
}


void TMatrix::show_matrix() {
	cout << "\n";
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			cout << Matrix[i][j] << "  ";
		}
		cout << "\n\n";
	}
	cout << "\n";
}

int TripleMatrix::determinant() {
	return Matrix[0][0] * Matrix[1][1]*Matrix[2][2] + Matrix[0][1] * Matrix[2][0] * Matrix[1][2] + Matrix[1][0] * Matrix[2][1] * Matrix[0][2] - Matrix[2][0] * Matrix[1][1] * Matrix[0][2] - Matrix[0][0] * Matrix[1][2] * Matrix[2][1] - Matrix[2][2] * Matrix[1][0] * Matrix[0][1];
}

int result(DoubleMatrix db, TripleMatrix tp) {
	int res = tp.Sum() + tp.determinant() + db.determinant();
	return res;
}