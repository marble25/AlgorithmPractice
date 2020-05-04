#include <iostream>
#include <vector>
using namespace std;

int dp[100001][18], n;
vector<int> adj[100001];
void f(int h, int p) {
	dp[h][0] = 1e9;
	for (int i = 1; i < 18; i++) dp[h][i] += i;
	for (int it : adj[h]) if (it^p) {
		f(it, h);
		int f = 0, s = 0;
		for (int j = 1; j < 18; j++) {
			if (dp[it][s] > dp[it][j]) s = j;
			if (dp[it][f] > dp[it][s]) swap(f, s);
		}
		for (int j = 1; j < 18; j++) dp[h][j] += dp[it][f^j ? f : s];
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	f(1, 0);
	int min = dp[1][1];
	for (int i = 1; i <= 17; i++) {
		if (min > dp[1][i]) {
			min = dp[1][i];
		}
	}
	cout << min;
}