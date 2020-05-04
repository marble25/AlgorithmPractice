#include <iostream>
using namespace std;
int main() {
	int n;
	int arr[55];
	int re[55] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[i] || (arr[i] == arr[j] && j < i)) {
				re[i] ++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << re[i] << " ";
	}
}