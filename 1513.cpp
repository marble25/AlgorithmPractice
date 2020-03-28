//
// Created by marble on 20. 3. 29..
//

// 힌트 없이 풀 수 있었음
// 조건이 까다로워서 여러번 생각해보고 가능한지 생각해봤음
// 완전탐색, BFS 등 모든 가능성 열어보고 생각하다가 결국 bottom-up 방식으로 해결


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

const int MOD = 1000007;

int n, m, c;
int map[55][55] = {0};
long long dp[55][55][55][55] = {0}; // x, y, max_index, num

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> c;
    for(int i=1;i<=c;i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = i;
    }

    if(map[1][1] > 0) { // 처음 시작점이 오락실이면
        dp[1][1][map[1][1]][1] = 1; // max_index는 map[1][1] 값, 지나온 오락실 갯수는 1
    } else { // 시작점이 오락실이 아니면
        dp[1][1][0][0] = 1; // max_index, 지나온 오락실 갯수 모두 0
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int k=0;k<=c;k++) {
                if(i+1 <= n) { // i+1 방향 진행 가능하면
                    if(map[i+1][j] > k) { // 기존의 max_index보다 큰 값이 들어오면
                        for(int l=0;l<=c;l++) {
                            dp[i+1][j][map[i+1][j]][l+1] += dp[i][j][k][l]; // 새로운 max_index : map[i+1][j], 오락실 지나온 갯수 : +1
                            dp[i+1][j][map[i+1][j]][l+1] %= MOD;
                        }
                    } else if(map[i+1][j] == 0) { // 오락실 아니면 그냥 값 더해줌
                        for(int l=0;l<=c;l++) {
                            dp[i+1][j][k][l] += dp[i][j][k][l];
                            dp[i+1][j][k][l] %= MOD;
                        }
                    }
                }
                if(j+1 <= m) {
                    if(map[i][j+1] > k) { // max_index보다 큰 값이 들어오면
                        for(int l=0;l<=c;l++) {
                            dp[i][j+1][map[i][j+1]][l+1] += dp[i][j][k][l]; // 새로운 max_index : map[i][j+1], 오락실 지나온 갯수 : +1
                            dp[i][j+1][map[i][j+1]][l+1] %= MOD;
                        }
                    } else if(map[i][j+1] == 0) { // 오락실 아니면 그냥 값 더해줌
                        for(int l=0;l<=c;l++) {
                            dp[i][j+1][k][l] += dp[i][j][k][l];
                            dp[i][j+1][k][l] %= MOD;
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<=c;i++) {
        long long result = 0;
        for(int j=0;j<=c;j++) {
            result += dp[n][m][j][i];
            result %= MOD;
        }
        cout << result << ' ';
    }
    return 0;
}