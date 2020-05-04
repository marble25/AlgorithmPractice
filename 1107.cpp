#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	int arr[10] = { 0 };
	cin >> n >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		arr[x] = 1;
	}
	if (abs(n - 100) < 3 || n == 103) {
		cout << abs(n - 100);
		return 0;
	}

	if (n == 0) {
		for (int j = 0; j < 10; j++) {
			if (arr[j] == 0) {
				cout << j + 1;
				return 0;
			}
		}
	}

	int min = abs(n-100);
	for (int i = 0; i <= 1000000; i++) {
		bool flag = false;
		int temp = i;
		int count = 0;
		
		if (i == 0) {
			if (arr[0] == 1) {
				count = 0;
			}
			else {
				count = 1;
			}
		}
		else {
			while (temp > 0) {
				x = temp % 10;
				if (arr[x] == 1) {
					flag = true;
					break;
				}
				temp /= 10;
				count++;
			}
		}
		

		if (flag == false && count > 0) {
			if (count + abs(n - i) < min) {
				min = count + abs(n - i);
			}
		}
	}

	cout << min;

}
