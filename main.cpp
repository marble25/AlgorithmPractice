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

int n, l, r;
int mp[55][55] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[55][55] = {0};
int area[2505] = {0};
queue<pair<int, int>> tq;

void bfs(int sx, int sy, int cnt) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    visited[sx][sy] = cnt;
    q.push({sx, sy});

    int sum = 0;
    int cells = 0;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        cells ++;
        sum += mp[x][y];
        v.push_back({x, y});

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 1 || my < 1 || mx > n || my > n) continue;
            if(abs(mp[x][y] - mp[mx][my]) < l || abs(mp[x][y] - mp[mx][my]) > r) continue;
            if(visited[mx][my] != 0) continue;

            visited[mx][my] = cnt;
            q.push({mx, my});
        }
    }

    int value = sum / cells;
    if(cells == 1) return;

    for(auto &it:v) {
        mp[it.first][it.second] = value;
        tq.push({it.first, it.second});
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> r;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> mp[i][j];
            tq.push({i, j});
        }
    }

    int ans = 0;
    while(!tq.empty()) {
        int cnt = 1;
        memset(visited, 0, sizeof(visited));

        int qsize = tq.size();
        for(int i=0;i<qsize;i++) {
            if(visited[tq.front().first][tq.front().second] == 0) {
                bfs(tq.front().first, tq.front().second, cnt++);
            }
            tq.pop();
        }
        ans ++;
    }
    cout << ans - 1;

    return 0;
}