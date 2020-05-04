#include <iostream>
#include <cstring>
using namespace std;
int stack[100][2], top = 0;
int isEmpty() {
	return top == 0;
}
void push(int x) {
	stack[++top][0] = x;
	stack[top][1] = 0;
}
int pop() {
	if (stack[top][1] == 0) {
		stack[top - 1][1] += (stack[top][1] + 1) * stack[top][0];
	}
	else {
		stack[top - 1][1] += (stack[top][1]) * stack[top][0];
	}
	
	return stack[top--][0];
}
int getTop() {
	return stack[top][0];
}
int main() {
	char input[40];

	cin >> input;
	for (int i = 0; i < std::strlen(input); i++) {
		switch (input[i]) {
		case '(':
			push(2);
			
			break;
		case ')':
			if (isEmpty()) {
				cout << "0\n";
				return 0;
			}
			if (getTop() != 2) {
				cout << "0\n";
				return 0;
			}
			pop();
			break;
		case '[':
			push(3);
			break;
		case ']':
			if (isEmpty()) {
				cout << "0\n";
				return 0;
			}
			if (getTop() != 3) {
				cout << "0\n";
				return 0;
			}
			pop();
			break;
		}

	}

	if (!isEmpty()) {
		cout << "0\n";
		return 0;
	}

	cout << stack[0][0] * stack[1][1] + stack[0][1] <<"\n";
}