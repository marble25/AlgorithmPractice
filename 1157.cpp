#include <iostream>
#include <cstring>
using namespace std;
char s[1000008];

int main() {
	int max = -1, count = 0, max_i;
	int a[26] = { 0 };
	cin >> s;
	int size = strlen(s);
	for (int i = 0; i < size; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			a[s[i] - 'a'] ++;
		}
		else {
			a[s[i] - 'A'] ++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max < a[i]) {
			count = 0;
			max = a[i];
			max_i = i;
		}
		else if (max == a[i]) {
			count++;
		}
	}
	if (count != 0) {
		cout << "?";
	}
	else {
		cout << (char)(max_i + 'A');
	}
}