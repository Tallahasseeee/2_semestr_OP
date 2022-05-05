#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class TMatrix {
protected:
	int** Matrix;
	int size;
public:
	TMatrix();
	int** get_matrix();
	int get_size();
	int Sum();
	virtual int determinant() = 0;
	void show_matrix();
};

class DoubleMatrix : public TMatrix {
public:
	DoubleMatrix();
	int determinant() override ;
};

class TripleMatrix : public TMatrix {
public:
	TripleMatrix();
	int determinant() override ;
};

int result(DoubleMatrix, TripleMatrix);

