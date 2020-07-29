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

void bfs(int start_x, int start_y) {
    int sz = 1;
    q.push({start_x, start_y});
    visited[start_x][start_y] = 1;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int cx = x + dx[i], cy = y + dy[i];
            if(cx < 1 || cy < 1 || cx > n || cy > m) continue;
            if(arr[cx][cy] == 0) continue;
            if(visited[cx][cy] == 1) continue;

            visited[cx][cy] = 1;
            q.push({cx, cy});
            sz++;
        }
    }
    group[cnt] = sz;

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
        }
    }

    ans = max(ans, sz+1);
    cnt++;
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
            if(arr[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 1) continue;

            set<int> s;
            for(int k=0;k<4;k++) {
                int cx = i + dx[k], cy = j + dy[k];
                if(cx < 1 || cy < 1 || cx > n || cy > m) continue;
                if(arr[cx][cy] == 0) continue;
                s.insert(visited[cx][cy]);
            }

            int sz = 1;
            for(auto &it:s) {
                sz += group[it];
            }

            ans = max(sz, ans);
        }
    }

    cout << ans;
    return 0;
}