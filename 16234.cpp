//
// Created by marble on 20. 5. 14..
//

// bfs를 이용해서 간단하게 풀어주었다.

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
int changed_mp[55][55] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[55][55] = {0};
int area[2505] = {0};

void bfs(int sx, int sy, int cnt) {
    queue<pair<int, int>> q;

    visited[sx][sy] = cnt;
    q.push({sx, sy});

    int sum = 0;
    int cells = 0;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        // 방문한 정점의 값을 더해줌
        cells ++;
        sum += mp[x][y];

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 1 || my < 1 || mx > n || my > n) continue;
            if(abs(mp[x][y] - mp[mx][my]) < l || abs(mp[x][y] - mp[mx][my]) > r) continue;
            if(visited[mx][my] == cnt) continue;


            visited[mx][my] = cnt;
            q.push({mx, my});
        }
    }

    int value = sum / cells;
    area[cnt] = value; // 다른 배열에다 설정된 값을 넣어줌
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> r;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    while(true) {
        int cnt = 1;
        memset(visited, 0, sizeof(visited));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(visited[i][j] == 0) {
                    bfs(i, j, cnt++);
                }
            }
        }
        if(cnt > n * n) {
            break;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                mp[i][j] = area[visited[i][j]];
            }
        }
        ans ++;
    }
    cout << ans;

    return 0;
}