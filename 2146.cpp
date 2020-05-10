//
// Created by marble on 20. 5. 10..
//

// 그렇게 어렵지 않은 bfs 문제였다.
// 깔끔하게 바로 solve

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


int n;
int mp[105][105] = {0};
int area[105][105] = {0};
int ans = INT32_MAX;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void set_area(int x, int y, int a) {
    queue<pair<int, int>> q;

    q.push({x, y});
    area[x][y] = a;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(mp[mx][my] == 1 && area[mx][my] == 0) {
                area[mx][my] = a;
                q.push({mx, my});
            }
        }
    }
}

int shortest_bridge(int x, int y) {
    queue<pair<int, int>> q;
    int visited[105][105] = {0};
    int a = area[x][y];

    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(mp[mx][my] == 0 && visited[mx][my] == 0) {
                visited[mx][my] = visited[x][y] + 1;
                q.push({mx, my});
            } else if(mp[mx][my] == 1 && area[mx][my] != a) {
                return visited[x][y];
            }
        }
    }
    return INT32_MAX;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mp[i][j];
        }
    }
    int area_cnt = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(mp[i][j] == 1 && area[i][j] == 0) {
                set_area(i, j, area_cnt++); // 각각의 area에 대한 번호를 붙여놓음
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(mp[i][j] == 0) continue;
            bool near_ocean = false;

            for(int k=0;k<4;k++) {
                int mx = i + dx[k];
                int my = j + dy[k];
                if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                if(mp[mx][my] == 0) {
                    near_ocean = true;
                    break;
                }
            }

            if(near_ocean) { // 바다와 붙어있다면 가장 짧은 다리 탐색
                int ret = shortest_bridge(i, j);
                ans = min(ret, ans);
            }
        }
    }

    cout << ans-1;
    return 0;
}