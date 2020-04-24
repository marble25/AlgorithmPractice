//
// Created by marble on 20. 4. 24..
//

// 문제가 조금 모호했던 문제
// 그래도 원콤에 풀었다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n, m;
int map[15][15] = {0};
int min_t = INT32_MAX;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void bfs() {
    priority_queue<pair<int, pair<int, int>>> q; // 더 가까운 곳을 먼저 탐색하기 위해 priority queue 사용
    int visited[15][15] = {0};
    int bridge_used[15][15] = {0};

    q.push({-1, {0, 0}});
    visited[0][0] = 1;

    while(!q.empty()) {
        int x = q.top().second.first, y = q.top().second.second;
        q.pop();

        if(x == n-1 && y == n-1) { // 종료 조건이면 min값 업데이트
            min_t = min(min_t, visited[x][y]);
            continue;
        }

        for(int i=0;i<4;i++) {
            int moved_x = x + dx[i];
            int moved_y = y + dy[i];

            if(moved_x < 0 || moved_y < 0 || moved_x >= n || moved_y >= n) continue;
            if(map[moved_x][moved_y] == 0) continue;

            if(visited[moved_x][moved_y] == 0) visited[moved_x][moved_y] = 987654321;

            if(map[moved_x][moved_y] == 1) { // 단순한 길이면
                if(visited[moved_x][moved_y] > visited[x][y] + 1) { // 기존 값보다 더 작은 값이면 업데이트
                    q.push({-visited[x][y], {moved_x, moved_y}});
                    visited[moved_x][moved_y] = visited[x][y] + 1;
                    bridge_used[moved_x][moved_y] = 0; // 오작교를 사용하지 않았다고 체크
                }
            } else {
                int cycle = map[moved_x][moved_y];
                int new_value = ((visited[x][y] + (cycle-1)) / cycle) * cycle; // 오작교를 건널 수 있는 주기 계산
                if(visited[moved_x][moved_y] > new_value + 1 && bridge_used[x][y] == 0) { // 기존 값보다 더 작고 직전에 오작교 이용 안했으면 업데이트
                    visited[moved_x][moved_y] = new_value + 1;
                    q.push({-(new_value+1), {moved_x, moved_y}});
                    bridge_used[moved_x][moved_y] = 1; // 오작교를 사용했다고 체크
                }
            }


        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map[i][j];
        }
    }

    bfs(); // 절벽이 없는 경우도 카운트

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j] != 0) continue; // 절벽이 아니라면 continue

            bool cliff_x = false;
            bool cliff_y = false;
            if(i-1 >= 0 && map[i-1][j] == 0) cliff_x = true;
            if(i+1 < n && map[i+1][j] == 0) cliff_x = true;
            if(j-1 >= 0 && map[i][j-1] == 0) cliff_y = true;
            if(j+1 < n && map[i][j+1] == 0) cliff_y = true;
            if(cliff_x && cliff_y) continue; // 교차한다면 continue

            map[i][j] = m; // 오작교를 놓아봄
            bfs();
            map[i][j] = 0; // 오작교 회수
        }
    }

    cout << min_t - 1;

    return 0;
}