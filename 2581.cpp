#include <iostream>
using namespace std;
bool arr[10001];
int main() {
	int n, m, min = -999;
	cin >> m >> n;
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
	for (int i = m; i <= n; i++) {
		if (arr[i] == false) {
			if (min == -999) {
				min = i;
			}
			count += i;
		}
	}
	if (min == -999) {
		cout << "-1";
		return 0;
	}
	cout << count << "\n";
	cout << min;
}