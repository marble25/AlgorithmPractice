#include <cstring>
#include <iostream>

using namespace std;
int main() {
	int t, n;
	int queue[10005], front=-1, rear=0;
	char command[10];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (std::strcmp(command, "push") == 0) {
			cin >> n;
			queue[++front] = n;
		}
		else if (std::strcmp(command, "front") == 0) {
			if (front-rear != -1) {
				cout << queue[rear] << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (std::strcmp(command, "back") == 0) {
			if (front-rear != -1) {
				cout << queue[front] << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (std::strcmp(command, "pop") == 0) {
			if (front < rear) {
				cout << -1 << "\n";
			}
			else {
				cout << queue[rear++] << "\n";
			}
		}
		else if (std::strcmp(command, "size") == 0) {
			cout << (front - rear + 1) << "\n";
		}
		else if (std::strcmp(command, "empty") == 0) {
			cout << (front - rear == -1 ? 1 : 0) << "\n";
		}
	}
}