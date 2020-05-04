#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	long long n, l, s;
	cin >> n >> l;
	for (long long i = l; i <= 100; i++) {
		s = n / i - i / 2;
		if (i % 2 == 0) {
			s++;
		}
		if (s < 0) {
			continue;
		}
		long long sum = 0;
		for (long long j = s; j < s + i; j++) {
			sum += j;
		}

		if (sum == n) {
			for (long long j = s; j < s + i; j++) {
				cout << j << " ";
			}
			return 0;
		}
	}

	cout << "-1";
}