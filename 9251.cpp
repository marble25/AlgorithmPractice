#include <iostream>
#include <cstring>
int arr[1005][1005];
using namespace std;
int main() {
	char s1[1005], s2[1005];
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < strlen(s1); i++) {
		arr[i][0] = 0;
	}
	for (int j = 0; j < strlen(s2); j++) {
		arr[0][j] = 0;
	}

	int size_x = strlen(s1);
	int size_y = strlen(s2);

	int max = -99;

	for (int i = 1; i <= size_x; i++) {
		for (int j = 1; j <= size_y; j++) {
			
			if (s1[i-1] == s2[j-1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				if (arr[i][j - 1] > arr[i - 1][j]) {
					arr[i][j] = arr[i][j - 1];
				}
				else {
					arr[i][j] = arr[i - 1][j];
				}
			}
		}
	}
	for (int i = 1; i <= size_x; i++) {
		for (int j = 1; j <= size_y; j++) {
			if (max <  arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	cout << max << "\n";
}