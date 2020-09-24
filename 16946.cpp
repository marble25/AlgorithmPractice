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
char arr[1005][1005] = {0};
int visited[1005][1005] = {0};
int ans[1005][1005] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int group = 0;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    stack<pair<int, int>> stk;

    q.push({x, y});
    stk.push({x, y});
    visited[x][y] = group;

    int cnt = 1;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 1 || my < 1 || mx > n || my > m) continue;
            if(visited[mx][my] != 0 || arr[mx][my] == '1') continue;
            visited[mx][my] = group;
            stk.push({mx, my});
            q.push({mx, my});
            cnt++;
        }
    }

    while(!stk.empty()) {
        int x = stk.top().first, y = stk.top().second;
        stk.pop();
        ans[x][y] = cnt;
    }
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
            if(arr[i][j] == '0' && visited[i][j] == 0) {
                group++;
                bfs(i, j);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == '0') {
                cout << 0;
                continue;
            }
            int temp = 0;
            set<pair<int, int>> s;
            for(int k=0;k<4;k++) {
                int x = i + dx[k], y = j + dy[k];
                if(x < 1 || y < 1 || x > n || y > m) continue;
                s.insert({visited[x][y], ans[x][y]});
            }

            for(auto &it:s) {
                temp += it.second;
            }

            cout << (temp + 1) % 10;
        }
        cout << '\n';
    }

    return 0;
}
