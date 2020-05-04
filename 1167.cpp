#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
map<pair<int, int>, int> m;
vector<int> tree[100005];
queue<int> q;
int visit[100005];
int result[100005];
void bfs(int x) {
	q.push(x);
	visit[x] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		int range = tree[x].size();
		for (int i = 0; i < range; i++) {
			if (visit[tree[x][i]] == 0) {
				q.push(tree[x][i]);
				visit[tree[x][i]] = 1;
				result[tree[x][i]] = result[x] + m[{x, tree[x][i]}];
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (true) {
			int a, b;
			cin >> a;
			if (a == -1) {
				break;
			}
			cin >> b;
			m[{x, a}] = b;
			tree[x].push_back(a);
		}
	}
	bfs(1);
	int max = -1, re_idx;
	for (int i = 1; i <= n; i++) {
		if (result[i] > max) {
			max = result[i];
			re_idx = i;
		}
		result[i] = 0;
		visit[i] = 0;
	}
	bfs(re_idx);
	max = -1;
	for (int i = 1; i <= n; i++) {
		if (result[i] > max) {
			max = result[i];
		}
		result[i] = 0;
	}
	cout << max;
}