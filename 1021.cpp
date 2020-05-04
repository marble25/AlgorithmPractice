#include <deque>
#include <iostream>
using namespace std;
int main() {
	int n, m, result=0;
	int arr[50];
	deque<int> dq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int count = 0;
		int size = dq.size();

		while (1) {
			int tmp = dq.front();
			dq.pop_front();
			if (tmp == arr[i]) {
				result += (count < size - count ? count : size - count);
				break;
			}
			dq.push_back(tmp);
			count++;
		}
	}
	cout << result << "\n";
}