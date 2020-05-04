#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, m;
	int now = 1;
	int result[5005];
	queue<int> q;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 1; i < m; i++) {
			int f = q.front();
			q.pop();
			q.push(f);
		}
		result[now++] = q.front();
		q.pop();
	}
	cout << "<";
	for (int i = 1; i < n; i++) {
		cout << result[i] << ", ";
	}
	cout << result[n] << ">";
}