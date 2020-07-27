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

int ans = 0;
int mx = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    q.push({x, y});
    visited[x][y] = 1;
    int cnt = 1;

    while(!q.empty()) {
        x=q.front().first, y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int cx=x+dx[i], cy=y+dy[i];
            if(cx < 1 || cy < 1 || cx > n || cy > m) continue;
            if(arr[cx][cy] == 0) continue;
            if(visited[cx][cy] == 1) continue;
            visited[cx][cy] = 1;
            q.push({cx, cy});
            cnt++;
        }
    }

    ans++;
    mx = max(mx, cnt);
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

    cout << ans << "\n" << mx;

    return 0;
}