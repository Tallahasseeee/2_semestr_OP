#include "Header.h"

Polynom::Polynom() {
	first_coef = rand() % 100;
	second_coef = rand() % 100;
	third_coef = rand() % 100;
	fourth_coef = rand() % 100;
}

Polynom::Polynom(int first, int second, int third, int fourth) {
	first_coef = first;
	second_coef = second;
	third_coef = third;
	fourth_coef = fourth;
}

Polynom::Polynom(int coef) {
	first_coef = coef;
	second_coef = coef;
	third_coef = coef;
	fourth_coef = coef;
}

int Polynom::get_first_coef() { return first_coef; }
int Polynom::get_second_coef() { return second_coef; }
int Polynom::get_third_coef() { return third_coef; }
int Polynom::get_fourth_coef() { return fourth_coef; }

Polynom Polynom::operator+(Polynom second_polynom) {
	first_coef += second_polynom.first_coef;
	second_coef += second_polynom.second_coef;
	third_coef += second_polynom.third_coef;
	fourth_coef += second_polynom.fourth_coef;
	return *this;
}

Polynom Polynom::operator*(Polynom second_polynom) {
	first_coef *= second_polynom.first_coef;
	second_coef *= second_polynom.second_coef;
	third_coef *= second_polynom.third_coef;
	fourth_coef *= second_polynom.fourth_coef;
	return *this;
}

int Polynom::find_result(int x) {
	int res = pow(x, 3) * first_coef + pow(x, 2) * second_coef + pow(x, 1) * third_coef + pow(x, 0) * fourth_coef;
	return res;
}

int pow(int value, int degree) {
	int res = 1;
	for (size_t i = 0; i < degree; i++)
	{
		res *= value;
	}
	return res;
}

vector<int> input_coefs() {
	cout << "Enter 4 coefitients separated wuth gaps\n";
	string line;
	getline(cin, line);
	vector<int> coefs;
	for (size_t i = 0; i < 4; i++)
	{
		coefs.push_back(stoi(split(line, ' ')[i]));
	}
	
	return coefs;
}

vector<string> split(string str, char separator) {
	vector<string> res;
	string slice = "";
	str += " ";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == separator)
		{
			if (slice.length() > 0) {
				res.push_back(slice);
				slice = "";
			}
		}
		else {
			slice += str[i];
		}
	}
	res.push_back(slice);
	return res;
}

void Polynom::show_polynom() {
	cout << "\n" << first_coef << "X^3 + " << second_coef << "X^2 + " << third_coef << "X + " << fourth_coef << "\n";
}