//
// Created by marble on 20. 12. 14..
//

// 문제 조건을 너무 많이 간과해서 틀린 문제
// 어렵지는 않았는데 실수를 많이 했다.

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

int n, m, k;
int linked[305][305] = {0};
vector<pair<int, int>> link[305];
int cache[305][305] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i=0;i<k;i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a > b) continue; // 역 경로면 추가할 필요 없음
        linked[a][b] = max(linked[a][b], c); // 더 큰 값만 추가해줌
    }

    // 인접 리스트에 유효값만 넣어줌
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(linked[i][j] == 0) continue;
            link[i].push_back({j, linked[i][j]});
        }
    }

    for(int k=0;k<link[1].size();k++) { // 첫줄만 비용 추가(initialize)
        int next = link[1][k].first, cost = link[1][k].second;
        cache[1][next] = cost;
    }

    for(int i=2;i<m;i++) { // 둘째 줄부터
        for(int j=1;j<=n;j++) { // 시작점
            if(cache[i-1][j] == 0) continue; // 애초에 시작점을 i-1번만에 갈 수 없다면 continue
            for(int k=0;k<link[j].size();k++) { // 시작점과 연결된 정점
                int next = link[j][k].first, cost = link[j][k].second;
                cache[i][next] = max(cache[i][next], cache[i-1][j] + cost); // 더 큰 값으로 업데이트
            }
        }
    }

    int ans = 0;
    for(int i=1;i<m;i++) { // m번 이내로 갈 수 있는 정점 모두 찾아서 max
        ans = max(ans, cache[i][n]);
    }

    cout << ans;


    return 0;
}