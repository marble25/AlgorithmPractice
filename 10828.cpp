#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	int t, n;
	int stack[10005], top=-1;
	char command[10];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (std::strcmp(command, "push") == 0) {
			cin >> n;
			stack[++top] = n;
		}
		else if (std::strcmp(command, "top") == 0) {
			if (top != -1) {
				cout << stack[top] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (std::strcmp(command, "pop") == 0) {
			if (top != -1) {
				cout << stack[top--] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (std::strcmp(command, "size") == 0) {
			cout << (top+1) << endl;
		}
		else if (std::strcmp(command, "empty") == 0) {
			cout << (top==-1?1:0) << endl;
		}
	}
}