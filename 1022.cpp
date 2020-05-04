#include <iostream>
using namespace std;
int main() {
	int arr[55][10];
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int current = 1, temp_count = 2, temp = 1, temp_copy = 1;
	int x = 0, y = 0;
	if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
		arr[x - r1][y - c1] = current;
	}
	while (current < 10050 * 10050) {
		if (temp_count == 2 && temp_copy % 2 == 1) {
			y++;
		}
		else if (temp_count == 1 && temp_copy % 2 == 1) {
			x--;
		}
		else if (temp_count == 2 && temp_copy % 2 == 0) {
			y--;
		}
		else if (temp_count == 1 && temp_copy % 2 == 0) {
			x++;
		}
		
		current++;

		if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
			arr[x - r1][y - c1] = current;
		}

		temp--;
		if (temp == 0) {
			temp_count--;
			temp = temp_copy;
		}
		if (temp_count == 0) {
			temp_count = 2;
			temp = temp_copy + 1;
			temp_copy = temp;
		}
	}
	int max = -1;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	int count = 0;
	while (max > 0) {
		max /= 10;
		count++;
	}
	
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			if (j == 0) {
				cout.width(count);
			}
			else {
				cout.width(count + 1);
			}
			
			cout << arr[i][j];
		}
		cout << "\n";
	}
}