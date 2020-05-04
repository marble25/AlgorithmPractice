#include <iostream>
using namespace std;
int main() {
	int n;
	int arr[10001] = { 0 };
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (arr[i] > 0) {
			arr[i]--;
			cout << i << "\n";
		}
		
	}
}