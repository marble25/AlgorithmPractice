#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100005];
int result[100005];
int visit[100005];
queue<int> q;
void bfs() {
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (visit[x] != 0) {
			continue;
		}
		visit[x] = 1;
		int range = tree[x].size();
		for (int i = 0; i < range; i++) {
			if (visit[tree[x][i]] != 0) {
				continue;
			}
			q.push(tree[x][i]);
			result[tree[x][i]] = x;
		}
		tree[x].clear();
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	bfs();
	for (int i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}
}