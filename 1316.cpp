#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T, count = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		char s[105];
		bool check[26];
		int j;
		cin >> s;
		for (j = 0; j < 26; j++) {
			check[j] = false;
		}
		for (j = 0; j < strlen(s); j++) {
			if (check[s[j] - 'a'] == false) {
				check[s[j] - 'a'] = true;
			}
			else if (s[j - 1] == s[j]) {
				continue;
			}
			else {
				break;
			}
		}
		if (j == strlen(s)) {
			count++;
		}
	}
	cout << count;
}