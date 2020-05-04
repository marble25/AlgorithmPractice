#include <stdio.h>

int main() {
	int x, y;
	char day[7][4] = {"SUN", "MON","TUE", "WED", "THU", "FRI", "SAT" };
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d %d", &x, &y);
	int i, n, day_sum = 0;
	if (x > 1) {
		for (i = 0; i < x - 1; i++) {
			day_sum += month[i];
		}
		day_sum += y;
	}
	else
		day_sum = y;

	n = day_sum % 7;
	printf("%s", day[n]);


	return 0;
}