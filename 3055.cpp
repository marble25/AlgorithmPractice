//
// Created by marble on 20. 3. 24..
//

// 푸는데는 꽤 걸렸지만 깔끔하게 맞은 문제
// 푸는데 시간이 걸려도 정확하게 푸는 연습을 해야겠다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    int visited[55][55] = {0};
    char map[55][55];
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> map[i][j];
            if(map[i][j] == 'S') { // start 지점을 체크해놓는다.
                visited[i][j] = 1;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int time=1;time<=n*m;time++) { // n*m보다는 작을 것이다.
        queue<pair<int, int>> water_q;
        queue<pair<int, int>> q;

        // 현재 물이 차 있는 칸들을 water_q에 넣고, 물이 차있지 않고 고슴도치가 갈 수 있는 경로들은 q에 넣음
        // D가 만약 방문했던 노드면 시간을 출력
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(map[i][j] == 'D' && visited[i][j] != 0) {
                    cout << time-1;
                    return 0;
                }

                if(map[i][j] == '*') {
                    water_q.push(make_pair(i, j));
                } else if(visited[i][j] != 0) {
                    q.push(make_pair(i, j));
                }
            }
        }

        // 현재 물이 차 있는 칸과 인접한 칸을 물 채움.
        while(!water_q.empty()) {
            pair<int, int> p = water_q.front();
            water_q.pop();

            for(int i=0;i<4;i++) {
                int moved_x = p.first + dx[i];
                int moved_y = p.second + dy[i];
                if(map[moved_x][moved_y] != 'D' && map[moved_x][moved_y] != 'X') map[moved_x][moved_y] = '*';
            }
        }

        // 이전 타임에 갈 수 있는 노드들에서 추가로 한칸씩 더 가봄(갈 수 있는 경로에 한해서)
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for(int i=0;i<4;i++) {
                int moved_x = p.first + dx[i];
                int moved_y = p.second + dy[i];
                if(visited[moved_x][moved_y]) continue;
                if(map[moved_x][moved_y] == '.' || map[moved_x][moved_y] == 'D') {
                    visited[moved_x][moved_y] = 1;
                }
            }
        }

    }
    cout << "KAKTUS";
    return 0;
}