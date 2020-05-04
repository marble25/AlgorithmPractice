#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int level[10005];
int visit[10005];
int pos[10005];
int parent[10005];
pair<int, int> v[10005];
pair<int, int> width[10005];
queue<int> q;
int root;
int p = 1;
void find_root(int x) {
	while (parent[x]) {
		x = parent[x];
	}
	root = x;
}
void dfs(int x) {
	if (v[x].first != -1) {
		level[v[x].first] = level[x] + 1;
		dfs(v[x].first);
	}
	if (width[level[x]].first > p) {
		width[level[x]].first = p;
	}
	if (width[level[x]].second < p) {
		width[level[x]].second = p;
	}
	pos[x] = p++;
	if (v[x].second != -1) {
		level[v[x].second] = level[x] + 1;
		dfs(v[x].second);
	}
}
int main() {
	int n;
	cin >> n;

	int x, y, z;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		if (y != -1) {
			parent[y] = x;
		}
		if (z != -1) {
			parent[z] = x;
		}	
		v[x].first = y;
		v[x].second = z;
	}
	find_root(1);
	level[root] = 1;
	for (int i = 1; i <= 10000; i++) {
		width[i].first = 99999999;
		width[i].second = -99999999;
	}
	dfs(root);
	int max = -99999999;
	int idx;
	for (int i = 1; i <= 10000; i++) {
		if (max < width[i].second - width[i].first) {
			idx = i;
			max = width[i].second - width[i].first;
		}
	}
	cout << idx << " " << max + 1;
}