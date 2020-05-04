#include <iostream>
using namespace std;
int main() {
	int n;
	int arr[10] = { 0 };
	cin >> n;
	while (n > 0) {
		arr[n % 10] ++;
		n /= 10;
	}
	for (int i = 9; i >= 0; i--) {
		if (arr[i] > 0) {
			cout << i;
			arr[i]--;
			i++;
		}
	}
}