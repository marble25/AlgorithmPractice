//
// Created by marble on 20. 9. 12..
//

// 실수로 계속 틀렸었다
// 오랜만에 dp 문제를 풀어보니 좋았다

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

int n, c;
int dp[1005][10005] = {0};
const int MOD = 1000000007;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> c;
    int limit = 0;
    for(int i=2;i<=n;i++) {
        limit += i-1;
        dp[i][0] = 1;
        for(int j=1;j<=min(10000, limit);j++) {
            dp[i][j] = (dp[i][j-1]%MOD + dp[i-1][j]%MOD)%MOD;
            if(j - i >= 0) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
            }
        }
    }

    cout << dp[n][c];

    return 0;
}