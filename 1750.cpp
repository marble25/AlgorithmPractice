//
// Created by marble on 20. 3. 27..
//

// gcd를 dp에 저장한 후 진행해 주면 되는 문제
// 간단한 문제이지만 꽤 헤맸다...

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int N_MAX = 100;
const int MAX = 100000;
const int MOD = 10000003;

int arr[N_MAX+5];
int dp[N_MAX+5][MAX+5] = {0};

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++) {
        dp[i][arr[i]] = 1;
        if(i == 0) continue;

        for(int j=1;j<=arr[i];j++) {
            if(dp[i-1][j] == 0) continue;

            int gcd_val = gcd(arr[i], j);
            dp[i][gcd_val] = (dp[i][gcd_val] + dp[i-1][j]) % MOD; // arr[i]값을 gcd가 j인 집합의 원소로 넣었을 때
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD; // arr[i]값을 새로 추가하지 않았을 때
        }
    }

    cout << dp[n-1][1];

    return 0;
}