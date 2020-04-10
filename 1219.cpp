//
// Created by marble on 20. 4. 10..
//

// 음의 사이클에서 goal에 도달할 수 있는지를 체크하지 않아서 한번 틀렸던 문제
// 벨만-포드 알고리즘의 대표적 예이다.(음수 간선)

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

const long long INF = 1LL<<60;

int n, m;
int start, goal;
vector<pair<int, int>> linked[105];
long long cities[105] = {0};
long long dis[105];

void initialize() {
    for(int i=0;i<n;i++) {
        dis[i] = INF;
    }
    dis[start] = -cities[start]; // 돈을 버는 것은 음의 비용으로 생각
}

bool bfs(int x) { // x에서 goal에 도달할 수 있는지 체크
    queue<int> q;
    q.push(x);

    int visited[105] = {0};
    visited[x] = 1;

    while(!q.empty()) {
        x = q.front();
        q.pop();

        for(auto & it: linked[x]) {
            if(visited[it.first] == 0) {
                visited[it.first] = 1;
                q.push(it.first);
            }
        }
    }

    return (visited[goal] == 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> start >> goal >> m;
    for(int i=0;i<m;i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        linked[x].push_back(make_pair(y, cost));
    }
    for(int i=0;i<n;i++) {
        cin >> cities[i];
    }

    initialize();
    bool isCycle = false;
    for(int i=0;i<n;i++) { // n-2까지는 비용 계산, n-1은 음수 사이클 체크
        for(int j=0;j<n;j++) {
            for(auto & it : linked[j]) {
                int next = it.first;
                int next_cost = it.second;
                if(dis[j] != INF && dis[next] > dis[j] + next_cost - cities[next]) { // j에서 next로 가는 것이 기존 비용보다 쌀 때
                    dis[next] = dis[j] + next_cost - cities[next];

                    if(i == n-1 && (!isCycle)) { // n-1번 돌았는데도 아직도 업데이트 가능하다 -> 음수 사이클 존재
                        isCycle = bfs(next);
                    }
                }
            }
        }
    }

    if(dis[goal] == INF) { // 도달 불가능
        cout << "gg";
    } else if(isCycle) { // 음수 사이클 존재
        cout << "Gee";
    } else { // -비용 출력(벌어들인 돈이므로)
        cout << -dis[goal];
    }


    return 0;
}