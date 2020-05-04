#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int h, w;
		char s[15][15];
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < h; i++) {
			for (int j = w-1; j >= 0; j--) {
				cout << s[i][j];
			}
			cout << "\n";
		}
	}
}