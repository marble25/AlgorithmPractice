#include <iostream>
using namespace std;
#define PI 3.14159265358979
int main() {
	int n;
	cin >> n;
	cout << fixed;
	cout.precision(6);
	cout << (double)(n * n * PI) << "\n";
	cout << n * n * 2.0 << "\n";
}