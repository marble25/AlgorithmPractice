#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int arr[8005] = { 0 };
	int n, temp, max = -9999, min = -9999, mode = -9999, mode_i, center = -9999, current = 0;
	double avg = 0;
	bool change = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp + 4000] ++;
	}
	for (int i = 0; i <= 8000; i++) {
		current += arr[i];
		if (current >= (n + 1) / 2 && center == -9999) {
			center = i - 4000;
		}
		if (min == -9999 && arr[i] != 0) {
			min = i - 4000;
		}
		if (arr[i] != 0) {
			max = i - 4000;
			avg += (i - 4000) * arr[i];
		}
		if (arr[i] > mode) {
			mode = arr[i];
			mode_i = i - 4000;
			change = true;
		}
		else if (arr[i] == mode && change) {
			mode_i = i - 4000;
			change = false;
		}
	}
	avg /= n;

	int arithmeticmean = 0;
	if (avg == 0.0f)
	{
		arithmeticmean = 0;
	}
	else if (avg > 0.0f)
	{
		arithmeticmean = (int)floor(avg + 0.5);
	}
	else
	{
		arithmeticmean = (int)(avg - 0.5);
	}
	cout << arithmeticmean << "\n";
	cout << center << "\n";
	cout << mode_i << "\n";
	cout << max - min;
}