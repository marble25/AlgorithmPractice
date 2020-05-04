#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int sum = 0;
	char in[105];
	cin >> in;
	for (int i = 0; i < strlen(in); i++) {
		if (in[i] == 'c' && (in[i + 1] == '=' || in[i + 1] == '-')) {
			i++;
			sum++;
		}
		else if (in[i] == 'd' && in[i + 1] == 'z' && in[i + 2] == '=') {
			i += 2;
			sum++;

		}
		else if (in[i] == 'd' && in[i + 1] == '-') {
			i++;
			sum++;
		}
		else if (in[i] == 'l' && in[i + 1] == 'j') {
			i++;
			sum++;
		}
		else if (in[i] == 'n' && in[i + 1] == 'j') {
			i++;
			sum++;
		}
		else if (in[i] == 's' && in[i + 1] == '=') {
			i++;
			sum++;
		}
		else if (in[i] == 'z' && in[i + 1] == '=') {
			i++;
			sum++;
		}
		else {
			sum++;
		}
	}
	cout << sum;
}