#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char s[102];
	int a[26];
	for (int i = 0; i < 26; i++) {
		a[i] = -1;
	}
	cin >> s;
	for (int i = 0; i < strlen(s); i++) {
		if (a[s[i] - 'a'] == -1) {
			a[s[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}
}