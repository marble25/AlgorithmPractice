//
// Created by marble on 20. 3. 25..
//

// bfs로 돌면서 거리가 최대가 나오는 지점을 체크해 주면 되는 문제

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

const int MAX = 55;
char map[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int result = 1;

void bfs(int x, int y, int visited[MAX][MAX]) {
    visited[x][y] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        x = p.first;
        y = p.second;
        result = max(visited[x][y], result); // 거리가 최대인지 체크

        for(int i=0;i<4;i++) {
            int moved_x = x + dx[i];
            int moved_y = y + dy[i];

            if(map[moved_x][moved_y] == 'L' && visited[moved_x][moved_y] == 0) { // 방문한 적 없으면
                visited[moved_x][moved_y] = visited[x][y] + 1; // 현재까지 구한 거리에 +1
                q.push(make_pair(moved_x, moved_y));
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(map[i][j] == 'L') { // 모든 지점에 대해서 거리 체크를 해봄
                int visited[MAX][MAX] = {0};
                bfs(i, j, visited);
            }
        }
    }

    cout << result-1;

    return 0;
}