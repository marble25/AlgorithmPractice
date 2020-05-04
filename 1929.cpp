#include <iostream>
using namespace std;
bool arr[1000001];
int main() {
	int n, m, min = -999;
	cin >> m >> n;
	for (int i = 0; i < 1000001; i++) {
		arr[i] = false;
	}
	arr[1] = true;
	for (long long i = 2; i < 1000001; i++) {
		if (arr[i] == false) {
			for (long long j = 2; i*j < 1000001; j++) {
				arr[i*j] = true;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (arr[i] == false) {
			cout << i << "\n";
		}
	}
}