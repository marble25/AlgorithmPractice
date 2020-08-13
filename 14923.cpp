//
// Created by marble on 20. 8. 13..
//

// 시간이 생각보다 많이 나와서 아쉬운 문제
// 시간을 더 줄일 수 있는 방법을 생각해 봐야겠다

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
int hx, hy;
int ex, ey;
int arr[1005][1005] = {0};
int visited[2][1005][1005] = {0}; // 0번 부섰을 때 그 포인트를 방문했는지와 1번 부섰을 때 그 포인트를 방문했는지 체크하는 배열

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {hx, hy}});
    visited[0][hx][hy] = 1;

    while(!q.empty()) {
        int cnt = q.front().first;
        int x = q.front().second.first, y = q.front().second.second;
        q.pop();

        if(x == ex && y == ey) {
            cout << visited[cnt][x][y]-1;
            return;
        }

        for(int i=0;i<4;i++) {
            int cx = x + dx[i], cy = y + dy[i];
            if(cx < 1 || cy < 1 || cx > n || cy > m) continue;
            if(cnt == 1 && arr[cx][cy] == 1) continue; // 이미 1번 부섰는데 또 벽이 있으면
            if(cnt == 1 && visited[cnt][cx][cy] != 0) continue; // 이미 1번 부섰고, 그 포인트를 이미 방문했다면
            if(cnt == 0 && arr[cx][cy] == 0 && visited[cnt][cx][cy] != 0) continue; // 1번도 안부섰고, 벽이 아닌 그 포인트를 방문했다면
            if(cnt == 0 && arr[cx][cy] == 1 && visited[cnt+1][cx][cy] != 0) continue; // 1번도 안부섰고, 벽인 그 포인트를 방문했다면

            if(arr[cx][cy] == 1) { // 벽이면
                visited[cnt+1][cx][cy] = visited[cnt][x][y] + 1; // 부숴보기
                q.push({cnt+1, {cx, cy}});
            } else { // 벽 아니면
                visited[cnt][cx][cy] = visited[cnt][x][y] + 1; // 그대로 진행
                q.push({cnt, {cx, cy}});
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
    cin >> hx >> hy;
    cin >> ex >> ey;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }

    bfs();

    return 0;
}