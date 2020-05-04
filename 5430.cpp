#include <deque>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
	int t;
	int n;
	string input_raw;
	string command;
	deque<int> dq;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> command;
		cin >> n;
		cin >> input_raw;

		string num = "";
		bool isFront = true;
		bool status = true;
		dq.clear();

		for (int j = 0; j < input_raw.length(); j++) {
			if (input_raw[j] == ',' || input_raw[j] == ']') {
				if (input_raw[j-1] == '[') {
					break;
				}
				dq.push_back(atoi(num.c_str()));
				num = "";
			}
			else if (input_raw[j] != '[') {
				num += input_raw[j];
			}
		}

		for (int j = 0; j < command.length(); j++) {
			if (command[j] == 'R') {
				isFront = !isFront;
			}
			else if (command[j] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					status = false;
					break;
				}
				if (isFront) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}

		if (!status) {
			continue;
		}
		cout << "[";
		while (!dq.empty()) {
			if (isFront) {
				if (dq.size() == 1) {
					cout << dq.front();
				}
				else {
					cout << dq.front() << ",";
				}
				dq.pop_front();
			}
			else {
				if (dq.size() == 1) {
					cout << dq.back();
				}
				else {
					cout << dq.back() << ",";
				}
				dq.pop_back();
			}
			
		}
		cout << "]\n";
	}
}