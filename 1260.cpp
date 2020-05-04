#include <iostream>
using namespace std;
int visited[1005], con[1005][1005];
int n;
int queue[1005], front = 0, rear = -1;
void push(int x) {
	queue[++rear] = x;
}
int pop() {
	return queue[front++];
}
int isEmpty() {
	return front > rear;
}

void dfs(int x) {
	visited[x] = 1;
	cout << x+1 << " ";
	for (int i = 0; i < n; i++) {
		if (con[i][x] == 1 && visited[i] != 1) {
			dfs(i);
		}
	}
}
void bfs(int x) {
	visited[x] = 1;
	push(x);
	while (1) {
		if (isEmpty()) {
			break;
		}
		x = pop();
		cout << x+1 << " ";
		for (int i = 0; i < n; i++) {
			if (con[i][x] == 1 && visited[i] != 1) {
				visited[i] = 1;
				push(i);
			}
		}
	}
	
}
int main() {
	int m, v;
	int n1, n2;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		con[n1 - 1][n2 - 1] = 1;
		con[n2 - 1][n1 - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	dfs(v - 1);
	cout << "\n";
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	bfs(v - 1);
	cout << "\n";
}