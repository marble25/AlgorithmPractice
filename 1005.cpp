#include <iostream>
#include <queue>
using namespace std;

int con[1001][1001], re[1001], pay[1001], check[1001], visited[1001];
queue<int> q;

void initialize() {
	for (int i = 0; i < 1000; i++) {
		pay[i] = 0;
		check[i] = 0;
		visited[i] = 0;
		re[i] = 0;
		for (int j = 0; j < 1000; j++) {
			con[i][j] = 0;
		}
	}
}
int main() {
	int t;
	int n, k;
	int x, y;
	int w;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		initialize();
		for (int j = 0; j < n; j++) {
			cin >> pay[j];
			re[j] = pay[j];
		}
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			con[x-1][y-1] = 1;
			check[y - 1]++;
		}
		cin >> w;
		w = w - 1;

		for (int j = 0; j < n; j++) {
			if (check[j] == 0 && visited[j] == 0) {
				q.push(j);
			}
		}

		while (!q.empty()) {
			
			int a = q.front();
			visited[a] = 1;
			
			q.pop();

			for (int j = 0; j < n; j++) {
				if (con[a][j] == 1) {
					re[j] = (re[j] > pay[j] + re[a] ? re[j] : pay[j] + re[a]);
					con[a][j] = 0;
					check[j]--;
					if (check[j] == 0) {
						q.push(j);
					}
				}
			}
		}
		
		cout << re[w] << "\n";


	}
}