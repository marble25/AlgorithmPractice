//
// Created by marble on 20. 10. 8..
//

// 오랜만에 벨만 포드 연습을 해 보았다.
// 자꾸 잊어버리는 알고리즘을 계속 복습해야겠다.

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

int tc;
int n, m, w;
vector<pair<int, int>> linked[505];
int dis[505] = {0};

const int INF = 987654321;

bool bellmanFord() {
    dis[1] = 0;
    for(int i=0;i<n;i++) {
        bool change = false;
        for(int j=1;j<=n;j++) {
            for(auto &it:linked[j]) {
                int next = it.first, t = it.second;
                if(dis[next] > dis[j] + t) { // 거리가 더 작아질 여지가 있을 때
                    dis[next] = dis[j] + t;
                    change = true;
                }
            }
        }

        if(i == n-1 && change) { // n번째에도 업데이트가 있으면 음수 사이클 존재
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;
    while(tc--) {
        cin >> n >> m >> w;

        for(int i=0;i<505;i++) {
            linked[i].clear();
        }
        fill(dis, dis + 505, INF);

        for(int i=0;i<m;i++) {
            int s, e, t;
            cin >> s >> e >> t;
            linked[s].push_back({e, t});
            linked[e].push_back({s, t});
        }

        for(int i=0;i<w;i++) {
            int s, e, t;
            cin >> s >> e >> t;
            linked[s].push_back({e, -t});
        }

        if(!bellmanFord()) { // 음수 사이클이 있으면 가능
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }

    return 0;
}