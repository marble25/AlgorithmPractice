#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(const string &s1, const string &s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();
}
int main() {
	string str[20001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str, str + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i != 0 && str[i] == str[i - 1]) {
			continue;
		}
		cout << str[i] << "\n";
	}
}