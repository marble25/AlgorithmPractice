#include <iostream>
using namespace std;
bool check[10001];
void self_number(int x) {
	int sum = x;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	if (sum > 10000) {
		return;
	}
	check[sum] = true;
	self_number(sum);
}
int main() {
	for (int i = 1; i <= 10000; i++) {
		if (check[i] == false) {
			cout << i << "\n";
			self_number(i);
		}
	}
}