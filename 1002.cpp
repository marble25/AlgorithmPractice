#include <iostream>
#include <cmath>
using namespace std;
double getDistance(int x1, int x2, int y1, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
	int t;
	int x1, y1, r1, x2, y2, r2;

	cin >> t;

	int* result = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double disBetweenPoint = getDistance(x1, x2, y1, y2);
		if (disBetweenPoint == 0) {
			if (r1 == r2) {
				result[i] = -1;
			}
			else {
				result[i] = 0;
			}
		}
		else {
			if (abs(r1 - r2) < disBetweenPoint && disBetweenPoint < r1 + r2) {
				result[i] = 2;
			}
			else if (disBetweenPoint == abs(r1 - r2) || disBetweenPoint == r1 + r2) {
				result[i] = 1;
			}
			else if (disBetweenPoint > r1 + r2 || disBetweenPoint < abs(r1 - r2)) {
				result[i] = 0;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
}