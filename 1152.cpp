#include <iostream>
#include <cstring>
using namespace std;
char a[1000003];
int main() {
	cin.getline(a, sizeof(a));
	
	int count = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ' && a[i+1] != ' ') {
			count++;
		}
	}
	if (a[0] != ' ') {
		count++;
	}
	if (a[strlen(a) - 1] == ' ') {
		count--;
	}
	cout << count;
}