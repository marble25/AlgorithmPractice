//
// Created by 이지호 on 21. 5. 15..
//

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

int m, n, h;
int arr[101][101][101] = {0};

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int visited[101][101][101] = {0};
queue<pair<int, pair<int, int>>> q;

int bfs() {
    while(!q.empty()) {
        int z = q.front().first, x = q.front().second.first, y = q.front().second.second;
        q.pop();

        for(int i=0;i<6;i++) {
            int mx = x + dx[i], my = y + dy[i], mz = z + dz[i];
            if(mx < 0 || my < 0 || mz < 0 || mz >= h || mx >= n || my >= m) continue;
            if(visited[mz][mx][my] != 0) continue;
            if(arr[mz][mx][my] != 0) continue;
            q.push({mz, {mx, my}});
            visited[mz][mx][my] = visited[z][x][y] + 1;
        }
    }

    int mx = -1;
    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                if(arr[i][j][k] == 0 && visited[i][j][k] == 0) return -1;
                mx = max(mx, visited[i][j][k]);
            }
        }
    }
    return mx;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h;
    bool tomato = false;
    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 0) tomato = true;
                if(arr[i][j][k] == 1) {
                    q.push({i, {j, k}});
                    visited[i][j][k] = 0;
                }
            }
        }
    }

    if(q.empty() && !tomato) {
        cout << 0;
        return 0;
    }

    cout << bfs();

    return 0;
}