//
// Created by marble on 20. 9. 10..
//

// 쉬운 문제인데 한 번에 패스를 못해서 아쉬운 문제
// 불을 먼저 퍼트리고, 사람을 보내서 갈 수 있는지 확인하면 되는 문제

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

int n, m;
string in;
int arr[1005][1005];

pair<int, int> fire;
pair<int, int> st;

queue<pair<int, int>> q;
int visited[1005][1005] = {0};
int checked[1005][1005] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> in;
        for(int j=0;j<m;j++) {
            if(in[j] == '#') { // 벽이면
                arr[i][j] = 1;
            } else if(in[j] == '.') { // 아무 것도 아니면
                arr[i][j] = 0;
            } else { // 사람이거나 불이면
                arr[i][j] = 0;
                if(in[j] == 'J') {
                    st = {i, j};
                } else { // 불은 미리 queue에 추가해놓음
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    while(!q.empty()) { // 불을 bfs 돌림
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i];
            int my = y + dy[i];

            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(arr[mx][my] != 0 || visited[mx][my] != 0) continue; // 벽이거나 이미 방문했으면

            visited[mx][my] = visited[x][y] + 1;
            q.push({mx, my});
        }
    }

    q.push(st); // 사람을 이용해서 bfs
    checked[st.first][st.second] = 1;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i];
            int my = y + dy[i];

            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(arr[mx][my] != 0 || checked[mx][my] != 0) continue; // 벽이거나 이미 방문했으면
            if(visited[mx][my] != 0 && visited[mx][my] <= checked[x][y] + 1) continue; // 불이 있는 지역이면(visited가 0이 아닌 것 체크하는 것이 중요)

            checked[mx][my] = checked[x][y] + 1;
            q.push({mx, my});
        }
    }

    int ans = 987654321; // 최단 거리를 업데이트
    for(int i=0;i<n;i++) {
        if(checked[i][0] != 0) ans = min(ans, checked[i][0]);
        if(checked[i][m-1] != 0) ans = min(ans, checked[i][m-1]);
    }

    for(int j=0;j<m;j++) {
        if(checked[0][j] != 0) ans = min(ans, checked[0][j]);
        if(checked[n-1][j] != 0) ans = min(ans, checked[n-1][j]);
    }

    if(ans == 987654321) cout << "IMPOSSIBLE";
    else cout << ans;

    return 0;
}