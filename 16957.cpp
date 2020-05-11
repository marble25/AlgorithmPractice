//
// Created by marble on 20. 5. 11..
//

// 작은 시간초과 줄이는 방법으로 시간초과가 나고 안나고 할 수 있다.

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


int r, c;
int mp[505][505] = {0};
int linked[505][505] = {0};
int ans[505][505] = {0};

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int x, int y) {
    if(linked[x][y] != -1) return linked[x][y];

    int min_val = INT32_MAX;
    int min_x, min_y;
    for(int k=0;k<8;k++) {
        int mx = x + dx[k];
        int my = y + dy[k];
        if(mx < 0 || my < 0 || mx >= r || my >= c) continue;
        if(mp[mx][my] < mp[x][y] && mp[mx][my] < min_val) {
            min_val = mp[mx][my];
            min_x = mx;
            min_y = my;
        }
    }

    if(min_val == INT32_MAX) { // 주변에서 가장 작은 노드라면
        linked[x][y] = x * 1000 + y; // 해당 좌표값을 넣어줌
    } else { // 아니면 작은 노드로 탐색
        linked[x][y] = dfs(min_x, min_y);
    }
    return linked[x][y];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(linked, -1, sizeof(linked)); // -1로 초기화

    cin >> r >> c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> mp[i][j];
        }
    }

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(linked[i][j] == -1) { // 방문 안했다면
                dfs(i, j);
            }

            // 모이는 정점을 구해서 거기에 공 갯수 추가
            int x = linked[i][j] / 1000;
            int y = linked[i][j] % 1000;
            ans[x][y] ++;

        }
    }

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}