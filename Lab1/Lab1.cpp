#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	string first_file_name = "first file.txt";
	string second_file_name = "second file.txt";
	inputFile(first_file_name);
	cout << "First file:\n";
	outputFile(first_file_name);
	create_second_file(first_file_name, second_file_name);
	cout << "Second file:\n";
	outputFile(second_file_name);

}

