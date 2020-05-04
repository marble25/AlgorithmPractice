#include <iostream>
using namespace std;
int main() {
	int a, max = -1;
	int arr[10] = { 0 };
	cin >> a;
	while (a > 0) {
		arr[a % 10]++;
		a /= 10;
	}
	int dif = arr[6] - arr[9];
	dif /= 2;
	arr[9] += dif;
	arr[6] -= dif;
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max;
}