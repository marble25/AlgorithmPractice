//
// Created by marble on 20. 5. 29..
//

// DP를 이용한 메모이제이션을 사용해서 시간복잡도 문제 해결
// n이 20이라서 우습게 보고 풀었다가 시간초과가 나와서 cache에 저장하는 방식을 택했다.

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
int mp[25][25] = {0};
int cache[25][25][25][25][2] = {0};

int cut_check(int sx, int sy, int ex, int ey) { // cut한 부분에 보석이 있으면 -1 출력, 아니면 0 출력
    for(int i=sx;i<=ex;i++) {
        for(int j=sy;j<=ey;j++) {
            if(mp[i][j] == 2) {
                return -1;
            }
        }
    }
    return 0;
}

int check(int sx, int sy, int ex, int ey) { // 석판에 불순물 없고 보석이 딱 1개라면 0 출력, 아니면 -1 출력
    int cnt = 0;
    for(int i=sx;i<=ex;i++) {
        for(int j=sy;j<=ey;j++) {
            if(mp[i][j] == 1) {
                return -1;
            }
            if(mp[i][j] == 2) {
                cnt ++;
            }
        }
    }

    if(cnt != 1) {
        return -1;
    }
    return 0;
}

int f(int sx, int sy, int ex, int ey, int dir) {
    int ans = 0;
    if(cache[sx][sy][ex][ey][dir] != -1) { // 캐시 저장되어 있으면 그 값 출력
        return cache[sx][sy][ex][ey][dir];
    }

    if(dir == 0) { // 가로 방향으로 자른다.
        for(int j=sy+1;j<ey;j++) {
            int cut = cut_check(sx, j, ex, j); // 자른 부분
            if(cut != 0) continue;

            int up = check(sx, sy, ex, j-1); // 위쪽 부분
            int down = check(sx, j+1, ex, ey); // 아래쪽 부분

            if(up == 0 && down == 0) { // 올바르게 분할되면
                ans ++;
            } else {
                int re = 1;
                if(up == -1) { // 위쪽 부분이 잘못되었으면
                    re *= f(sx, sy, ex, j-1, 1-dir);
                }
                if(down == -1) { // 아래쪽 부분이 잘못되었으면
                    re *= f(sx, j+1, ex, ey, 1-dir);
                }
                ans += re;
            }
        }
    } else {
        for(int i=sx+1;i<ex;i++) {
            int cut = cut_check(i, sy, i, ey); // 자른 부분
            if(cut != 0) continue; // 자른 부분에 보석이 있으면 다른 방법 시도

            int left = check(sx, sy, i-1, ey); // 왼쪽 부분
            int right = check(i+1, sy, ex, ey); // 오른쪽 부분

            if(left == 0 && right == 0) { // 올바르게 분할되면
                ans ++;
            } else {
                int re = 1;
                if(left == -1) { // 왼쪽 부분이 잘못되었으면 왼쪽을 다시 분할
                    re *= f(sx, sy, i-1, ey, 1-dir);
                }

                if(right == -1) { // 오른쪽 부분이 잘못되었으면 오른쪽을 다시 분할
                    re *= f(i+1, sy, ex, ey, 1-dir);
                }
                ans += re;
            }
        }
    }

    cache[sx][sy][ex][ey][dir] = ans; // 값 대입
    return ans;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> mp[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));

    if(check(1, 1, n, n) == 0) { // 분할 없이 가능하다면
        cout << 1;
    } else {
        int re = f(1, 1, n, n, 0) + f(1, 1, n, n, 1); // 가로 방향 분할과 세로 방향 분할 모두 고려
        if(re == 0) cout << -1;
        else cout << re;
    }

    return 0;
}