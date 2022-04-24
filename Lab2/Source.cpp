#include "Header.h";

struct client {
	string surname;
	string name;
	int hrs;
	int mins;
	int dur;
	bool state;
	void save(string line) {
		vector <string> arr = split(line, ' ');
		if (arr.size() > 3) {
			state = true;
			surname = arr[0];
			name = arr[1];
			dur = stoi(arr[3]);
			if (count(arr[2].begin(), arr[2].end(), ':')) {
				vector <string> tm = split(arr[2], ':');
				hrs = stoi(tm[0]);
				mins = stoi(tm[1]);
			}
			else {
				state = false;
				cout << "Wrong time format\n";
			}
		}
		else {
			state = false;
			cout << "Wrong format\n";
		}
	}
};

void input_file(string filePath) {
	string line;
	cout << "Enter client info in format: Surname Name Time(HH:MM) Duration(in minutes)\n";
	getline(cin, line);
	while (line!="") {
		client person;
		person.save(line);
		if (person.state) {
			if (check_time(filePath, person) == true) {
				ofstream file(filePath, ios::app);
				if (!file.is_open()) {
					cout << "ERROR: could not open";
				}
				else {
					file << line + '\n';
				}
				file.close();
			}
			else {
				cout << "No time\n";
			}
		}
		getline(cin, line);
	}

}

bool check_time(string filePath,client person) {
	string line = " ";
	bool flag = true;
	ifstream File(filePath);
	bool chk;
	while (!File.eof()) {
		getline(File, line);
		client person1;
		if (line !="") {
			person1.save(line);
		}
		chk = ((person1.hrs * 60 + person1.mins + person1.dur > person.hrs * 60 + person.mins) && (person1.hrs * 60 + person1.mins + person1.dur < person.hrs * 60 + person.mins + person.dur)) || ((person.hrs * 60 + person.mins + person.dur > person1.hrs * 60 + person1.mins) && (person.hrs * 60 + person.mins + person.dur < person1.hrs * 60 + person1.mins + person1.dur));
		if (chk) {
			flag = false;
		}

	}
	File.close();
	return flag;
}

void show_late_clients(string filePath) {
	ifstream file(filePath);
	string line = "";
	cout << "\nClients that will come after 16:30:\n";
	while (!file.eof()) {
		getline(file, line);
		client person;
		if (line != "") {
			person.save(line);
		}
		if (person.hrs*60 + person.mins > 16*60 + 30) {
			cout << line << "\n";
		}
	}
	file.close();
}


vector<string> split(string str, char separator)
{
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