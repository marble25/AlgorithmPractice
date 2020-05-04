#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a;
		char re[200], in[25];
		cin >> a;
		cin >> in;
		for (int j = 0; j < strlen(in); j++) {
			for (int k = 0; k < a; k++) {
				re[j*a + k] = in[j];
			}
		}
		re[strlen(in) * a] = '\0';
		cout << re << "\n";
	}

}