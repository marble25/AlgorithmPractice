//
// Created by marble on 20. 3. 28..
//

// DP는 역시 너무 어렵다.
// DP를 잘 풀 수 있는 사람이 되고 싶다....

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

int n, m;
long long dp[1005][1005][2] = {0}; // dp[i][j][k] : i~j까지 중 0이면 커서가 i, 1이면 커서가 j에 위치할 때 앞으로 발생할 비용의 최소
long long arr[1005][2];
long long sum[1005] = {0};

long long f(int start, int end, int cur) {
    if(start == 1 && end == n) return 0;

    long long &ret = dp[start][end][cur];
    if(ret != -1) return ret;

    int now = cur?end:start;
    long long on = sum[n] - sum[end] + sum[start-1]; // 안가본 가로등(켜져 있는 가로등)의 전력 합

    if(start-1 >= 1) {
        long long tmp = f(start-1, end, 0) + (arr[now][0]-arr[start-1][0]) * on; // 왼쪽으로 향하는 것 + 안가본 가로등 전력합 * 다음 가로등까지의 거리
        ret = tmp;
    }

    if(end+1 <= n) {
        long long tmp = f(start, end+1, 1) + (arr[end+1][0] - arr[now][0]) * on; // 오른쪽으로 향하는 것 + 안가본 가로등 전력합 * 다음 가로등까지의 거리
        if(ret == -1 || ret > tmp) ret = tmp;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> arr[i][0] >> arr[i][1];
        sum[i] = sum[i-1] + arr[i][1];
    }

    memset(dp, -1, sizeof(dp));
    cout << f(m, m, 0);

    return 0;
}