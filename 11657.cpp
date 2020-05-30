//
// Created by marble on 20. 5. 31..
//

// 벨만 포드로 풀어보았는데
// 단순 Distance 기반 BFS가 더 빠른 것 같다.
// 성능 개선이 필요하다.

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

int n, m;
int linked[505][505] = {0};

long long dis[505];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            linked[i][j] = INT32_MAX;
        }
    }

    for(int i=0;i<m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        linked[x][y] = min(linked[x][y], z);
    }

    fill(dis, dis+505, INT32_MAX);
    dis[1] = 0;

    for(int i=0;i<n-1;i++) {
        for(int from=1;from<=n;from++) {
            for(int to=1;to<=n;to++) {
                if(linked[from][to] == INT32_MAX) continue;
                if(dis[from] == INT32_MAX) continue;
                long long d = dis[from] + linked[from][to];
                if(d < dis[to]) {
                    dis[to] = d;
                }
            }
        }
    }

    for(int from=1;from<=n;from++) {
        for(int to=1;to<=n;to++) {
            if(linked[from][to] == INT32_MAX) continue;
            if(dis[from] == INT32_MAX) continue;
            long long d = dis[from] + linked[from][to];
            if(d < dis[to]) {
                cout << -1;
                return 0;
            }
        }
    }

    for(int i=2;i<=n;i++) {
        if(dis[i] == INT32_MAX) cout << -1 << "\n";
        else cout << dis[i] << "\n";
    }

    return 0;
}