//
// Created by marble on 20. 4. 19..
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

int n, m, h;
int map[15][30];
int ans = 987654321;

bool check(int cnt) {
    for(int i=1;i<=n;i++) {
        int x = i;
        for(int j=1;j<=h;j++) {
            if(map[x][j] == 1) {
                x++;
            } else if(map[x-1][j] == 1) {
                x--;
            }
        }
        if(x != i) return false;
    }
    return true;
}

void f(int idx, int cnt) {
    if(cnt >= 4) return;
    if(check(cnt)) {
        ans = min(ans, cnt);
        return;
    }
    for(int i=idx;i<n;i++) {
        for(int j=1;j<=h;j++) {
            if(map[i][j] == 1) continue;
            if(map[i-1][j] == 1) continue;
            if(map[i+1][j] == 1) continue;

            map[i][j] = 1;
            f(i, cnt+1);
            map[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> h;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        map[y][x] = 1;
    }

    f(1, 0);
    if(ans == 987654321) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}