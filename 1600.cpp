//
// Created by marble on 20. 3. 31..
//

// 메모리 초과가 나서 당황했던 문제..
// 계산해 보아도 메모리 초과가 날 만큼 크지는 않았는데...
// dp와 bfs를 합쳐서 재밌는 문제를 풀어보았다.

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

int K;
int W, H;
int map[205][205] = {0};
int dp[205][205][35] = {0};
queue<pair<pair<int, int>, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dhorsex[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dhorsey[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// 2, 2 시작
// 도착지 : 1+H, 1+W

void update_dp(int x, int y, int movedx, int movedy, int k, int is_horse) {
    if(map[movedx][movedy] != 0) return;
    if(dp[movedx][movedy][k+is_horse] != 0) { // dp 값이 저장되어 있다면 가장 작은 값으로 업데이트
        dp[movedx][movedy][k+is_horse] = min(dp[x][y][k]+1, dp[movedx][movedy][k+is_horse]);
        return;
    }
    q.push(make_pair(make_pair(movedx, movedy), k+is_horse));
    dp[movedx][movedy][k+is_horse] = dp[x][y][k]+1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> K;
    cin >> W >> H;
    memset(map, -1, sizeof(map)); // 주위에 벽을 만들어줌
    for(int i=2;i<=H+1;i++) {
        for(int j=2;j<=W+1;j++) {
            cin >> map[i][j];
        }
    }

    q.push(make_pair(make_pair(2, 2), 0));
    dp[2][2][0] = 1;

    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second, k = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) { // 원숭이 태세
            int movedx = x + dx[i], movedy = y + dy[i];
            update_dp(x, y, movedx, movedy, k, 0);
        }

        if(k == K) continue; // 말로 움직일 수 없는 상태라면 continue
        for(int i=0;i<8;i++) { // 말 태세
            int movedx = x + dhorsex[i], movedy = y + dhorsey[i];
            update_dp(x, y, movedx, movedy, k, 1);
        }
    }

    // K보다 적게 움직인 값들 중 최소를 구함
    int min_val = INT32_MAX;
    for(int i=0;i<=K;i++) {
        if(dp[1+H][1+W][i] == 0) continue;
        min_val = min(dp[1+H][1+W][i], min_val);
    }

    if(min_val == INT32_MAX) {
        cout << -1;
    } else {
        cout << min_val-1;
    }
    return 0;
}