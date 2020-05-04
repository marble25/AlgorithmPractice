#include <iostream>
using namespace std;
int total;
int arr[10] = { 0 };
int start_idx = -1;
void check(int start_index, int start_number) {
	if (start_index == -1) {
		total -= 1;
		return;
	}
	for (int i = 0; i <= start_number; i++) {
		arr[9 - start_index] = i;
		check(start_index - 1, i - 1);
		if (total == -9999) {
			return;
		}
		if (total < 0) {
			total = -9999;
			for (int j = 9-start_idx; j < 10; j++) {
				cout << arr[j];
				
			}
			return;
		}
	}
}
int main() {
	int n;
	int comb[9] = { 10, 45, 120, 210, 252, 210, 120, 45, 10 };
	
	cin >> n;
	if (n == 1022) {
		cout << "9876543210";
		return 0;
	}
	for (int i = 0; i < 9; i++) {
		total += comb[i];
		if (total > n) {
			start_idx = i;
			break;
		}
	}
	if (start_idx == -1) {
		cout << "-1";
		return 0;
	}
	total -= comb[start_idx];
	total = n - total;
	check(start_idx, 9);

}