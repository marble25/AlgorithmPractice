#include <iostream>
using namespace std;
int arr[100005];
int sum[100005];
#define max(a, b) a>b?a:b
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int result = arr[0];
	sum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		sum[i] = max(sum[i - 1] + arr[i], arr[i]);
		result = max(result, sum[i]);
	}
	result = max(result, sum[0]);

	cout << result;
}

