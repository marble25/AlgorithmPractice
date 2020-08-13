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
int visited[2][1005][1005] = {0};

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
            if(cnt == 1 && arr[cx][cy] == 1) continue;
            if(cnt == 1 && visited[cnt][cx][cy] != 0) continue;
            if(cnt == 0 && arr[cx][cy] == 0 && visited[cnt][cx][cy] != 0) continue;
            if(cnt == 0 && arr[cx][cy] == 1 && visited[cnt+1][cx][cy] != 0) continue;

            if(arr[cx][cy] == 1) {
                visited[cnt+1][cx][cy] = visited[cnt][x][y] + 1;
                q.push({cnt+1, {cx, cy}});
            } else {
                visited[cnt][cx][cy] = visited[cnt][x][y] + 1;
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