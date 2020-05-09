//
// Created by marble on 20. 5. 9..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int n, k;
pair<int, int> walk[105];
pair<int, int> bike[105];
int dp[100005] = {0};


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> walk[i].first >> walk[i].second;
        cin >> bike[i].first >> bike[i].second;
    }

    if(walk[0].first <= k) {
        dp[walk[0].first] = max(dp[walk[0].first], walk[0].second);
    }

    if(bike[0].first <= k) {
        dp[bike[0].first] = max(dp[bike[0].first], bike[0].second);
    }

    for(int i=1;i<n;i++) {
        for(int j=k;j>=0;j--) {
            if(dp[j] == 0) continue;
            int time = j, cost = dp[j];
            int bike_time = time + bike[i].first, bike_cost = cost + bike[i].second;
            int walk_time = time + walk[i].first, walk_cost = cost + walk[i].second;

            if(bike_time <= k) {
                dp[bike_time] = max(bike_cost, dp[bike_time]);
            }
            if(walk_time <= k) {
                dp[walk_time] = max(walk_cost, dp[walk_time]);
            }
            dp[time] = 0;
        }
    }

    int ans = INT32_MIN;
    for(int i=0;i<=k;i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;


    return 0;
}