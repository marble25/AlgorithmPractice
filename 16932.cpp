//
// Created by marble on 20. 7. 29..
//

// 처음에는 BFS를 2번 돌렸다가 맞긴 했지만 시간이 너무 많이 나온듯 하여 소스코드를 변경했다.
// 그래도 시간이 여전히 너무 많이 나오는 것 같기는 하다.

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
int arr[1005][1005] = {0};
int visited[1005][1005] = {0};
int group[1000005] = {0};
queue<pair<int, int>> q;
int cnt = 2;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

void bfs(int start_x, int start_y) { // 해당되는 영역의 visited를 cnt로 채워준다
    int sz = 1;
    q.push({start_x, start_y});
    visited[start_x][start_y] = cnt;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int cx = x + dx[i], cy = y + dy[i];
            if(cx < 1 || cy < 1 || cx > n || cy > m) continue;
            if(arr[cx][cy] == 0) continue;
            if(visited[cx][cy] == cnt) continue;

            visited[cx][cy] = cnt;
            q.push({cx, cy});
            sz++;
        }
    }
    group[cnt++] = sz; // cnt를 증가시켜 주면서 group에 size를 할당한다. 즉, cnt(group index)와 size를 매핑
    ans = max(ans, sz+1);
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 1 && visited[i][j] == 0) { // 아직 탐색하지 않은 지점이면 bfs
                bfs(i, j);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 1) continue; // 0인 지점에 대해서만 체크

            set<int> s;
            for(int k=0;k<4;k++) {
                int cx = i + dx[k], cy = j + dy[k];
                if(cx < 1 || cy < 1 || cx > n || cy > m) continue;
                if(arr[cx][cy] == 0) continue;
                s.insert(visited[cx][cy]); // 중복을 피하기 위해서 set을 사용
            }

            int sz = 1; // 현재 위치를 0에서 1로 바꾸므로 size가 1에서 시작
            for(auto &it:s) {
                sz += group[it]; // 중복되지 않는 size들을 더해줌
            }

            ans = max(sz, ans);
        }
    }

    cout << ans;
    return 0;
}