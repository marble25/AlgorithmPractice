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

int n, m, a, b, k;
int mp[505][505] = {0};

int visited[505][505] = {0};
pair<int, int> st, en;

bool corrupts(int u_x, int u_y, int dir) {
    switch (dir) {
        case 1: // 위쪽
            if(u_x-1 < 1) return true;
            for(int i=0;i<b;i++) {
                if(mp[u_x-1][u_y+i] == 1) return true;
            }
            return false;
        case 2: // 아래
            if(u_x+1 > n) return true;
            for(int i=0;i<b;i++) {
                if(mp[u_x+1][u_y+i] == 1) return true;
            }
            return false;
        case 3: // 왼쪽
            if(u_y-1 < 1) return true;
            for(int i=0;i<a;i++) {
                if(mp[u_x+i][u_y-1] == 1) return true;
            }
            return false;
        case 4: // 오른쪽
            if(u_y+1 > m) return true;
            for(int i=0;i<a;i++) {
                if(mp[u_x+i][u_y+1] == 1) return true;
            }
            return false;
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin >> a >> b;
    cin >> k;
    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }

    cin >> st.first >> st.second;
    cin >> en.first >> en.second;



    return 0;
}