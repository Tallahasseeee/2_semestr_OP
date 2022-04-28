#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
private:
	string surname;
	string name;
	string father_name;
	int day;
	int month;
	int year;
public:
	Person();
	Person(string);
	string get_surname();
	string get_name();
	string get_father_name();
	int get_day();
	int get_month();
	int get_year();
	void show_info();
};

Person* create_array(int len);

vector<Person> find_happy_dates(Person*, int);

bool ben(Person);

void output(vector<Person>);

vector<string> split(string, char);