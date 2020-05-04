#include <iostream>
using namespace std;
int main() {
	int n;
	int input;
	long long arr[101] = { 0 };
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	for (int i = 9; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << arr[input] << "\n";
	}
}