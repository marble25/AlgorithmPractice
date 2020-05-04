#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int sum = 0;
	string arr[9] = {"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	char in[20];
	cin >> in;
	for (int i = 0; i < strlen(in); i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[j].find(in[i]) != -1) {
				sum += 2 + j;
			}
		}
	}
	cout << sum;
}