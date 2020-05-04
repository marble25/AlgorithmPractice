#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int* input = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> input[i];
	}

	int arr[41][2];
	for (int i = 0; i < 41; i++) {
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
	arr[0][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}

	for (int i = 0; i < t; i++) {
		cout << arr[input[i]][0] << " " << arr[input[i]][1] << endl;
	}
}