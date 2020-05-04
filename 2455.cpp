#include <iostream>
using namespace std;
int main() 
{
	int count = 0;
	int a, b;
	int max = -9;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		count -= a;
		count += b;
		if (count > max) {
			max = count;
		}
	}
	cout << max;
}