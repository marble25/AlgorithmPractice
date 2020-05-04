#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

bool prime[2000000] = { false };
bool square[2000000] = { false };
vector < unsigned long long int > p;
int p_size = 0;	int s_size = 0;

int main() {
	unsigned long long int min, max;
	unsigned long long int temp, t_min, t_max;

	scanf("%llu %llu", &min, &max);
	temp = sqrtl((long double)max);

	prime[0] = prime[1] = true;
	for (unsigned long long int i = 2; i <= temp; i++) {
		if (prime[i]) continue;
		for (unsigned long long int j = i * 2; j <= temp; j += i) {
			if (prime[j]) continue;
			prime[j] = true;
		}
		p.push_back(i*i);
		p_size++;
	}

	for (unsigned long long int i = 0; i<p_size; i++) {
		if (min % p[i]) {
			t_min = ((unsigned long long int)(min / p[i]) + 1) * p[i];
		}
		else {
			t_min = min;
		}

		t_max = (unsigned long long int)(max / p[i]) * p[i];

		for (unsigned long long int j = t_min; j <= t_max; j += p[i]) {
			if (square[j - min]) continue;
			square[j - min] = true;
		}
	}

	for (int i = 0; i <= max - min; i++) {
		if (!square[i]) s_size++;
	}

	printf("%d", s_size);
	return 0;
}