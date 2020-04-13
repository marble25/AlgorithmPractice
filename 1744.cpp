//
// Created by marble on 20. 4. 13..
//

// dp로 간단하게 푼 문제
// 무조건 이웃하는 수끼리 묶든 더하든 하는 것이 이득이라고 생각해서 묶은 것과 더한 것 중 최대를 항상 취하도록 알고리즘을 구현

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

int n;
int arr[10005] = {0};
long long dp[10005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    dp[0] = arr[0];
    if(n == 1) {
        cout << arr[0];
        return 0;
    }
    dp[1] = max(arr[0] + arr[1], arr[0] * arr[1]); // 더한 것과 묶은 것 중 최대를 저장
    for(int i=2;i<n;i++) {
        dp[i] = max(dp[i-1] + arr[i], dp[i-2] + arr[i] * arr[i-1]); // 이전 값에다 더한 것, 전전 값에 곱한 것을 더한 것중 최대를 찾음
    }
    cout << dp[n-1];
    return 0;
}