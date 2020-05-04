#include <iostream>
using namespace std;
int main() {
	int a;
	int arr[20001];
	arr[0] = 1;
	for (int i = 1; i <= 20000; i++) {
		arr[i] = arr[i - 1] + i*6;
	}
	cin >> a;
	for (int i = 0; i <= 20000; i++) {
		if (arr[i] >= a) {
			cout << i + 1;
			break;
		}
	}
}