#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char wear[50], type[50];
		int typeValue[30];
		int typeMax = 0;
		map<string, int> m;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> wear >> type;
			
			if (m.find(type) == m.end()) {
				m.insert(pair<string, int>(type, typeMax++));
				typeValue[typeMax - 1] = 1;
			}
			else {
				typeValue[m[type]]++;
			}
		}

		long long result = 1;
		for (int j = 0; j < typeMax; j++) {
			result *= (long long)(typeValue[j] + 1);
		}

		result -= 1;

		cout << result << "\n";
	}

}