#include <deque>
#include <iostream>
#include <cstring>

using namespace std;
int main() {
	int t, n;
	char command[20];
	deque<int> dq;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (std::strcmp(command, "push_front") == 0) {
			cin >> n;
			dq.push_front(n);
		} 
		else if (std::strcmp(command, "push_back") == 0) {
			cin >> n;
			dq.push_back(n);
		}
		else if (std::strcmp(command, "pop_front") == 0) {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			n = dq.front();
			dq.pop_front();
			cout << n << "\n";
		} 
		else if (std::strcmp(command, "pop_back") == 0) {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			n = dq.back();
			dq.pop_back();
			cout << n << "\n";
		} 
		else if (std::strcmp(command, "size") == 0) {
			cout << dq.size() << "\n";
		}
		else if (std::strcmp(command, "empty") == 0) {
			cout << dq.empty() << "\n";
		}
		else if (std::strcmp(command, "front") == 0) {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
		}
		else if (std::strcmp(command, "back") == 0) {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
		}
	}
}