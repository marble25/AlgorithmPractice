//
// Created by marble on 20. 8. 5..
//

// 구현하는 부분이 실수하기 쉬운 BFS문제였다.
// 그래도 깔끔하게 풀었다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <string.h>
using namespace std;

int n, m, a, b, k;
int mp[505][505] = {0};

int visited[505][505] = {0};
pair<int, int> st, en;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool corrupts(int u_x, int u_y, int dir) {
    switch (dir) {
        case 0: // 위쪽
            for(int i=0;i<b;i++) {
                if(mp[u_x][u_y+i] == 1) return true;
            }
            return false;
        case 1: // 아래쪽
            for(int i=0;i<b;i++) {
                if(mp[u_x+a-1][u_y+i] == 1) return true;
            }
            return false;
        case 2: // 왼쪽
            for(int i=0;i<a;i++) {
                if(mp[u_x+i][u_y] == 1) return true;
            }
            return false;
        case 3: // 오른쪽
            for(int i=0;i<a;i++) {
                if(mp[u_x+i][u_y+b-1] == 1) return true;
            }
            return false;
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            // 일단 다른 방향으로 한번 옮겨본다.
            int cx = x + dx[i];
            int cy = y + dy[i];

            if(cx < 1 || cy < 1 || cx+a-1 > n || cy+b-1 > m) continue;
            if(corrupts(cx, cy, i)) continue; // 옮긴 쪽으로 충돌하는지 체크(1줄만 체크하면 됨)
            if(visited[cx][cy] != 0) continue;

            q.push({cx, cy});
            visited[cx][cy] = visited[x][y] + 1;

            if(cx == en.first && cy == en.second) { // 도착점이라면 가는데 든 비용 출력
                cout << visited[cx][cy] - 1;
                return;
            }
        }
    }

    cout << -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin >> a >> b;
    cin >> k;
    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }

    cin >> st.first >> st.second;
    cin >> en.first >> en.second;

    bfs(st.first, st.second);

    return 0;
}