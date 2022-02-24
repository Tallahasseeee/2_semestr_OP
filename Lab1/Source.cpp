 #include "Header.h"

void inputFile(string name) {
	ofstream fileout;
	fileout.open(name);

	if (!fileout.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		cout << "Enter text (send empty line to finish):\n";
		getline(cin, line);
		while (!line.empty()) {
			fileout << line << "\n";
			getline(cin, line);
		}
	}

	fileout.close();
}

void outputFile(string name)
{
	ifstream filein;
	filein.open(name);

	if (!filein.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		while (!filein.eof()) {
			getline(filein, line);
			cout << line << "\n";
		}
	}

	filein.close();
}


void create_second_file(string filein_name, string fileout_name)
{
	ifstream filein;
	ofstream fileout;
	filein.open(filein_name);
	fileout.open(fileout_name);

	if (!filein.is_open() || !fileout.is_open()) {
		cout << "ERROR: Could not open";
	}
	else {
		string line;
		while (!filein.eof()) {
			getline(filein, line);
			if (!line.empty()) {
				vector<string> words = split(line);
				vector <string> numbers;
				string str = "";
				for (int i = 0; i < words.size(); i++) {
					str = "";
					for (int j = 0; j < words[i].size(); j++) {
						if (isDigit(words[i][j])) {
							str += words[i][j];
						}
						else if (isDigit(words[i][j]) == false && str != "") {
							numbers.push_back(str);
							str = "";
						}
					}
					if (str != "") {
						numbers.push_back(str);
					}
				}

				numbers = change_line(numbers);

				for (int i = 0; i < numbers.size(); i++) {
					fileout << numbers[i] << " , ";
				}
				fileout << "\n";
			}
		}
	}

	filein.close();
	fileout.close();
}

vector<string> split(string str)
{
	vector<string> res;
	string slice = "";
	str += " ";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
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
	return res;
}


bool isDigit(char ch) {
	if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0') {
		return true;
	}
	else {
		return false;
	}
}

vector<string> change_line(vector<string> numbers) {
	string max = "0";
	string memory;
	int index;
	for (int i = 0; i < numbers.size(); i++) {
		if (stoi(max) < stoi(numbers[i])) {
			max = numbers[i];
			index = i;
		}
	}
	memory = numbers[0];
	numbers[0] = max;
	numbers[index] = memory;
	return numbers;
}