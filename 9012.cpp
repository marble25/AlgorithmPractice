#include <iostream>
using namespace std;
int stack[100], top = -1;
int isEmpty() {
	return top == -1;
}
void push() {
	stack[++top] = 1;
}
int pop() {
	return stack[top--];
}
int main() {
	int t;
	char input[60];
	cin >> t;
	int* result = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> input;

		int flag = 0;
		top = -1;
		for (int j = 0; j < std::strlen(input); j++) {
			if (input[j] == '(') {
				push();
			}
			else {
				if (isEmpty()) {
					result[i] = 0;
					flag = 1;
					break;
				}
				pop();
			}
		}
		if (flag) {
			continue;
		}

		if (!isEmpty()) {
			result[i] = 0;
		}
		else {
			result[i] = 1;
		}
	}

	for (int i = 0; i < t; i++) {
		cout << (result[i] ? "YES\n" : "NO\n");
	}
}