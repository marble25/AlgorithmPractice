//
// Created by marble on 20. 3. 28..
//

// 100 단위로 나누어 떨어짐을 이용해서 100까지 dp 적용하고 이후부터는 그리디하게 풀어본 문제
// 1~99은 1, 10, 25를 조합해서 만들 수 있고, 100~10000은 n/100과 n%100으로 나누어 n/100은 1, 10, 25로 풀 수 있고, n%100도 마찬가지.

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

const long long MAX = 1000000000000000;
vector<long long> costs;
int dp[101] = {0};

void precalc() {
    for(long long i=1;i<=MAX;i*=10) {
        costs.push_back(i);
        if((int)log10(i) % 2 == 0) {
            costs.push_back(i*25);
        }

    }

    sort(costs.begin(), costs.end());

    for(int i=0;i<100;i++) { // dp 초기화
        dp[i] = i;
    }

    for(int k=0;k<4;k++) {
        for(int i=1;i<100;i++) {
            if(i < costs[k]) continue;
            if(dp[i-costs[k]] + 1 < dp[i]) { // 더 적은 비용으로 만들 수 있으면 업데이트
                dp[i] = dp[i-costs[k]] + 1;
            }
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
        long long n;
        cin >> n;

        int result = 0;
        while(n > 0) { // 두 자리씩 끊어가면서 더해줌
            int x = n % 100;
            result += dp[x];
            n /= 100;
        }
        cout << result << '\n';
    }
    return 0;
}