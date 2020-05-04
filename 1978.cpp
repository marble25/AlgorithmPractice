#include <iostream>
using namespace std;
bool arr[10001];
int main() {
	int n;
	int in[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < 10001; i++) {
		arr[i] = false;
	}
	arr[1] = true;
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == false) {
			for (int j = 2; i*j < 10001; j++) {
				arr[i*j] = true;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[in[i]] == false) {
			count++;
		}
	}
	cout << count;
}