#include <iostream>
#include <cmath>
using namespace std;
#define abs(a) a<0?-a:a
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}
int re[100000];
int main() 
{
	int n;
	int a[105], d[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		d[i-1] = abs((a[i] - a[i - 1]));
	}
	int g;
	if (n == 2) {
		g = d[0];
	}
	else {
		g = gcd(d[0], d[1]);
	}

	
	for (int i = 2; i < n - 1; i++) {
		g = gcd(g, d[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= sqrt(g); i++) {
		if (g % i == 0) {
			if (i != 1) {
				cout << i << " ";
			}
			if (g / i != i) {
				re[cnt++] = g / i;
			}
			
		}
	}
	for (int i = cnt - 1; i >= 0; i--) {
		cout << re[i] << " ";
	}
}