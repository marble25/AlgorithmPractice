#include <iostream>
using namespace std;
int stack[100005], top = -1;
int result[200010], resultNow = 0;
int isEmpty() {
	return (top == -1);
}
void push(int x) {
	stack[++top] = x;
	result[resultNow++] = 0;
}
int pop() {
	result[resultNow++] = 1;
	return stack[top--];
}
int getTop() {
	return stack[top];
}

int main() {
	
	int t, input[100005], now = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= t; i++) {
		if (isEmpty()) {
			push(i);
			continue;
		}

		if (input[now] > i) {
			push(i);
		}
		else if (input[now] == i) {
			push(i);
			pop();
			now++;
		}
		else if (input[now] < i) {
			if (!isEmpty() && getTop() == input[now]) {
				now++;
				pop();
				i--;
			}
			else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	while (!isEmpty()) {
		if (getTop() == input[now]) {
			now++;
			pop();
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < resultNow; i++) {
		cout << (result[i] ? "-" : "+") << "\n";
	}
}