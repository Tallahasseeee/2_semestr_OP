#include "Header.h"

Person::Person() {};

Person::Person(string line) {
	vector<string> info = split(line, ' ');
	surname = info[0];
	name = info[1];
	father_name = info[2];
	vector<string> date = split(info[3],'-');
	day = stoi(date[0]);
	month = stoi(date[1]);
	year = stoi(date[2]);
}

string Person::get_surname() { return surname; }

string Person::get_name() { return name; }

string Person::get_father_name() { return father_name; }

int Person::get_year() { return year; }

int Person::get_month() { return month; }

int Person::get_day() { return day; }

Person* create_array(int len) {
	Person* arr = new Person[len];
	cout << "Enter information about the person in format: Surname Name Father_name Date_of_birth_in_format(DD-MM-YY)\n";
	for (int i = 0; i < len; i++) {
		string line;
		getline(cin, line);
		arr[i] = Person(line);
	}
	return arr;
}

vector<Person> find_happy_dates(Person* arr,int len) {
	vector<Person> res;
	for (int i = 0; i < len; i++) {
		if (ben(arr[i])) {
			res.push_back(arr[i]);
		}
	}
	return res;
}

bool ben(Person person) {
	int d, m, y;
	if (person.get_day() < 10) {
		d = person.get_day()%7;
	}
	else {
		d = (person.get_day() / 10 + person.get_day() % 10)%7;
	}

	if (person.get_month() < 10) {
		m = person.get_month()%7;
	}
	else {
		m = (person.get_month() / 10 + person.get_month() % 10)%7;
	}

	if (person.get_year() < 10) {
		y = person.get_year()%7;
	}
	else {
		y = (person.get_day() / 10 + person.get_day() % 10)%7;
	}
	return d == m && m == y;
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

void Person::show_info() {
	cout << surname << ' ' << name << ' ' << father_name << ' ' << day << '-' << month << '-' << year << '\n';
}

void output(vector<Person> res) {
	cout << "\nPersons who was born on happy dates:\n\n";
	for (int i = 0; i < res.size(); i++) {
		res[i].show_info();
	}
}