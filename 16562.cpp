//
// Created by marble on 20. 10. 3..
//

// BFS를 이용해서 간단히 풀어본 문제

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

int n, m, k;
int cost[10005] = {0};
vector<int> linked[10005];

int visited[10005] = {0};
queue<int> q;

int total = 0;

void bfs(int x) {
    q.push(x);
    visited[x] = 1;
    int c = cost[x];

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto &it:linked[x]) {
            if(visited[it] == 0) {
                visited[it] = 1;
                c = min(c, cost[it]); // 연결된 아이들 중 최소 찾음
                q.push(it);
            }
        }
    }

    total += c; // 연결된 아이들 중 최소를 더해줌
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        cin >> cost[i];
    }

    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y);
        linked[y].push_back(x);
    }

    for(int i=1;i<=n;i++) {
        if(visited[i] == 0) {
            bfs(i);
        }
    }

    if(total > k) {
        cout << "Oh no";
    } else {
        cout << total;
    }

    return 0;
}