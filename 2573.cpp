//
// Created by marble on 20. 11. 22..
//

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
int arr[305][305] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void melt() {
    int arr2[305][305] = {0}; // 값 복사할 배열

    // 값을 복사
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arr2[i][j] = arr[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr2[i][j] == 0) continue; // 바다면 continue

            // 인접한 바다 개수 세기
            int cnt = 0;
            if(i-1 >= 0 && arr[i-1][j] == 0) {
                cnt++;
            }

            if(i+1 < n && arr[i+1][j] == 0) {
                cnt++;
            }

            if(j-1 >= 0 && arr[i][j-1] == 0) {
                cnt++;
            }

            if(j+1 < m && arr[i][j+1] == 0) {
                cnt++;
            }

            arr2[i][j] -= cnt; // 인접한 바다 개수만큼 녹이기
            if(arr2[i][j] < 0) arr2[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++) { // 변한 배열을 복사
        for(int j=0;j<m;j++) {
            arr[i][j] = arr2[i][j];
        }
    }

}

void bfs(int checked[][305], int x, int y) { // 그룹핑하기 위한 bfs
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(arr[mx][my] == 0 || checked[mx][my] == 1) continue;

            checked[mx][my] = 1;
            q.push({mx, my});
        }
    }
}

bool check_group(int time) {
    int checked[305][305] = {0};
    int group = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] != 0 && checked[i][j] == 0) { // 새로운 그룹 등장
                if(group == 1) { // 이미 하나 있으면 빙산이 2개 이상임
                    cout << time+1;
                    return true;
                }
                bfs(checked, i, j); // 연결된 곳을 모두 그룹핑
                group++;
            }
        }
    }

    if(group == 0) { // 그룹이 아예 없으면(빙산이 없으면)
        cout << 0;
        return true;
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }

    for(int time = 0;;time++) {
        melt();
        if(check_group(time)) break;
    }

    return 0;
}