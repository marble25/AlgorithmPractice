//
// Created by marble on 20. 3. 26..
//

// 점화식 생각해내는 것이 까다로웠던 문제
// 그래도 한번에 클리어

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

const int MAX = 100005;
const long long MOD = 1000000007;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    long long a[MAX];
    long long b[MAX];
    long long dp[MAX][3] = {0}; // i 난이도 고른 경우, i-1~i 난이도 고른 경우, i-2~i-1 난이도 고른 경우

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++) {
        cin >> b[i];
    }
    dp[0][0] = a[0]; // a[0] 고름
    dp[0][1] = b[0]; // b[0] 고름
    dp[0][2] = 0; // b[-1]은 없으므로 0

    for(int i=1;i<n;i++) {
        dp[i][0] = (a[i] * (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])) % MOD; // i-1 난이도, i-1~i 난이도, i-2~i-1 난이도 고른 것의 합에 자신의 경우를 곱함
        dp[i][1] = (b[i] * (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])) % MOD; // i-1 난이도, i-1~i 난이도, i-2~i-1 난이도 고른 것의 합에 자신의 경우를 곱함
        dp[i][2] = (b[i-1] * (dp[i-1][0] + dp[i-1][2])) % MOD; // i-1 난이도, i-2~i-1 난이도 고른 것의 합에 b[i-1]을 곱함
        if(b[i-1] > 0) {
            dp[i][2] = (dp[i][2] + dp[i-1][1] * (b[i-1]-1)) % MOD; // i-1~i 난이도에서 한번 뽑았기 때문에 남은 경우의 수는 b[i-1]-1
        }
    }
    cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) % MOD << '\n';
    return 0;
}