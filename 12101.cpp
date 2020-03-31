//
// Created by marble on 20. 3. 31..
//

// 한 번에 클리어한 문제
// dp는 조건이 항상 중요한 것 같다.

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

int dp[15];
char result[15];
int idx = 0;

void f(int num_left, int k) {
    for(int i=1;i<=3;i++) {
        if(num_left - i >= 0 && dp[num_left-i] >= k) { // dp 값이 k보다 크면 i 배열에 넣고 다시 탐색
            result[idx++] = (i + '0');
            f(num_left - i, k);
            break;
        }
        k -= dp[num_left-i];

    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=4;i<=11;i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int n, k;
    cin >> n >> k;

    if(k > dp[n]) {
        cout << -1;
        return 0;
    }
    f(n, k);

    int len = strlen(result);
    for(int i=0;i<len-1;i++) {
        cout << result[i] << '+';
    }
    cout << result[len-1];
    return 0;
}