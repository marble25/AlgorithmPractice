#include <cstdio>
#include <algorithm>

typedef struct MAP {
	int value;
	int index;
} map;

bool cmp(map a, map b) {
	return a.value < b.value;
}

map p[100000];
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		p[i].index = i;
		p[i].value = x;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		int now = 0;
		for (int j = 0; j < n; j++) {
			if (p[j].index >= x-1 && p[j].index <= y-1) {
				now++;
			}
			if (now == z) {
				printf("%d\n", p[j].value);
				break;
			}
		}
	}
}