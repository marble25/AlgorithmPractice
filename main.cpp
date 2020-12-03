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

int n, m, p;
int s[1005] = {0};
char in[1005];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int mp[1005][1005] = {0};

int visited[1005][1005] = {0};
queue<pair<int, int>> territory[1005];


bool isEnd() {
    bool flag = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mp[i][j] == 0) {
                flag = false;
            } else {
                visited[i][j] = 1;
            }
        }
    }
    return flag;
}

void printCastle() {
    int castle[1005] = {0};

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            castle[mp[i][j]] ++;
        }
    }

    for(int i=1;i<=p;i++) {
        cout << castle[i] << " ";
    }
}

void bfs(int player) {
    while(!territory[player].empty()) {
        int x = territory[player].front().first, y = territory[player].front().second;
        if(visited[x][y] > s[player]) break;

        territory[player].pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(mp[mx][my] != 0 || visited[mx][my] != 0) continue;

            visited[mx][my] = visited[x][y] + 1;
            mp[mx][my] = player;
            territory[player].push({mx, my});
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> p;
    for(int i=1;i<=p;i++) {
        cin >> s[i];
    }

    for(int i=0;i<n;i++) {
        cin >> in;
        for(int j=0;j<m;j++) {
            mp[i][j] = (in[j] == '.' ? 0 : (in[j] == '#' ? -1 : in[j] - '0'));
            if(mp[i][j] > 0) {
                territory[mp[i][j]].push({i, j});
            }
        }
    }

    while(true) {
        memset(visited, 0, sizeof(visited));

        if(isEnd()) {
            break;
        }

        for(int player=1;player<=p;player++) {
            bfs(player);
        }
    }

    printCastle();

    return 0;
}