#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

struct client;

void input_file(string);

vector<string> split(string, char);
void input_file(string);
bool check_time(string, client);
string get_line(string, int);
void show_late_clients(string filePath);