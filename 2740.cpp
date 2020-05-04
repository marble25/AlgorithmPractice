#include <cstdio>
using namespace std;
int main() {
	int n, m, k;
	int arr1[100][100], arr2[100][100], re[100][100];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			re[i][j] = 0;
			for (int l = 0; l < m; l++) {
				re[i][j] += arr1[i][l] * arr2[l][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", re[i][j]);
		}
		printf("\n");
	}
}