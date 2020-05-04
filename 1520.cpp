#include <iostream>
using namespace std;
int map[505][505];
int check[505][505] = { 0 };
int n, m;
int dfs(int x, int y) {
	if (check[x][y] != -1) {
		return check[x][y];
	}
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	check[x][y] = 0;
	if (x + 1 < n && map[x][y] > map[x + 1][y]) {
		check[x][y] += dfs(x + 1, y);
	}
	if (x - 1 >= 0 && map[x][y] > map[x - 1][y]) {
		check[x][y] += dfs(x - 1, y);
	}
	if (y + 1 < m && map[x][y] > map[x][y + 1]) {
		check[x][y] += dfs(x, y + 1);
	}
	if (y - 1 >= 0 && map[x][y] > map[x][y - 1]) {
		check[x][y] += dfs(x, y - 1);
	}
	return check[x][y];
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			check[i][j] = -1;
		}
	}
	dfs(0, 0);
	cout << check[0][0];
}