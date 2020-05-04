#include <iostream>

using namespace std;

int main() {
	int n, k;
	long long result;
	while (1) {
		result = 1;
		cin >> n >> k;
		if (n == k && n == 0) {
			break;
		}
		if (k < n - k) {
			k = n - k;
		}
		for (int i = n; i > k; i--) {
			result *= (long long)i;
			result /= (long long)(n + 1 - i);
		}
		
		cout << result << "\n";
	}
	
}