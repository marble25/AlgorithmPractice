//
// Created by marble on 20. 8. 16..
//

// 진짜 왜 런타임 에러를 수도 없이 맞았는지 모르겠는 문제
// 문제 알고리즘은 맞은 것 같은데 수도 없이 틀려서 화났었다.

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

int n, m;
vector<pair<int, int>> linked[1005];
int parent[1005] = {0};


int st, en;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y, c;
        cin >> x >> y >> c;
        linked[x].push_back({y, c});
    }
    cin >> st >> en;

    int dis[1005];

    memset(parent, -1, sizeof(parent)); // 부모를 모두 초기화
    fill(dis, dis+1005, 987654321); // 거리를 모두 가장 큰 값으로 초기화

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    dis[st] = 0;
    q.push({0, st});

    while(!q.empty()) {
        int cost = q.top().first, x = q.top().second;
        q.pop();

        if(dis[x] < cost) continue; // 기존 들어가 있는 값이 더 가까우면 이 경로를 탐색할 필요 없다

        for(int i=0;i<linked[x].size();i++) {
            int next = linked[x][i].first;
            int next_cost = linked[x][i].second + cost;

            if(dis[next] > next_cost) { // 다른 경로를 들렀다 가는 것이 더 빠르면 업데이트
                dis[next] = next_cost;

                parent[next] = x;
                q.push({next_cost, next});
            }
        }
    }

    stack<int> stk;

    int x = en;
    while(x != -1) { // 최상단(st)가 나올 때까지 올라감
        stk.push(x);
        x = parent[x];
    }

    cout << dis[en] << '\n';
    cout << stk.size() << '\n';

    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    return 0;
}