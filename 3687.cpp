//
// Created by marble on 20. 3. 30..
//

// 쉽게 생각했는데 쉽지는 않았던 문제
// 흠...

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

long long dp[105] = {0};
long long add[6] = {1, 7, 4, 2, 0, 8};

void precalc() {
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    dp[8] = 10; // dp[n-2]~dp[n-7]을 구해야 하는데, dp[1]이 정의되지 않았으므로 dp[8]까지 수동으로 넣어줌

    for(int i=9;i<=100;i++) {
        dp[i] = INT64_MAX;
        for(int j=2;j<=7;j++) { // 이전 값보다 새로 더하는 값이 작다면 업데이트
            dp[i] = min(dp[i-j] * 10 + add[j-2], dp[i]);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    precalc();

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        cout << dp[n];
        cout << ' ';
        if(n % 2 == 1) {
            cout << '7';
            n -= 3;
        }
        while(n > 0) {
            n -= 2;
            cout << '1';
        }
        cout << '\n';
    }

    return 0;
}