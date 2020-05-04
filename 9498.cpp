#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << (a >= 90 ? "A" : (a >= 80 ? "B" : (a >= 70 ? "C" : a >= 60 ? "D" : "F")));
}