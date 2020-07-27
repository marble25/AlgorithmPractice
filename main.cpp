#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int n, m;
int arr[505][505] = {0};
int visited[505][505] = {0};
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        x=q.front().first, y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            if()
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    return 0;
}