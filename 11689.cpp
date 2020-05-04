#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<long long, int> m;
int main() {
	long long n, temp;
	cin >> n;
	temp = n;
	int max = sqrt(n);
	for (long long i = 2;i<=max; i++) {
		while (n % i == 0) {
			if (m.count(i) == 0) {
				m[i] = 1;
			}
			else {
				m[i] ++;
			}
			n /= i;
		}
	}
	if (n > 1) {
		m[n] = 1;
	}
	map<long long, int>::iterator iter;
	long long count = temp;
	for (iter = m.begin(); iter != m.end(); ++iter) {
		count = count / (iter->first) * (iter->first - 1);
	}
	cout << count;
}