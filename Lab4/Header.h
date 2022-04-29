#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

class Polynom {
private:
	int first_coef;
	int second_coef;
	int third_coef;
	int fourth_coef;
public:
	Polynom();
	Polynom(int first, int second, int third, int fourth);
	Polynom(int coef);
	int get_first_coef();
	int get_second_coef();
	int get_third_coef();
	int get_fourth_coef();
	Polynom operator+(Polynom second_polynom);
	Polynom operator*(Polynom second_polynom);
	int find_result(int x);
	void show_polynom();
};

vector<int> input_coefs();

vector<string> split(string str, char separator);

int pow(int value, int degree);