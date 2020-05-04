#include <iostream>
using namespace std;
int main() {
	int n;
	int arr[60][2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				count++;
			}
		}
		cout << count << " ";
	}
}