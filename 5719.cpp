//
// Created by 이지호 on 21. 2. 27..
//

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
int s, d;
int u, v, p;
int linked[505][505] = {0};
int visited[505] = {0};
vector<int> parent[505];

void dijkstra() {
    priority_queue<pair<int, int>> pq;

    fill(visited, visited+n, 987654321);
    visited[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int x = pq.top().second;
        pq.pop();

        for(int i=0;i<n;i++) {
            if(linked[x][i] != 0 && visited[i] > visited[x] + linked[x][i]) {
                visited[i] = visited[x] + linked[x][i];
                parent[i] = {x};
                pq.push({-visited[i], i});
            } else if(linked[x][i] != 0 && visited[i] == visited[x] + linked[x][i]) {
                parent[i].push_back(x);
            }
        }
    }
}

void delete_parent(int current) {
    int sz = parent[current].size();
    for(int i=0;i<sz;i++) {
        linked[parent[current][i]][current] = 0;
        delete_parent(parent[current][i]);
    }
    parent[current].clear();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> s >> d;

        for(int i=0;i<500;i++) {
            parent[i].clear();
        }
        memset(linked, 0, sizeof(linked));

        for(int i=0;i<m;i++) {
            cin >> u >> v >> p;
            linked[u][v] = p;
        }
        dijkstra();
        delete_parent(d);
        dijkstra();
        if(visited[d] == 987654321) cout << -1 << "\n";
        else cout << visited[d] << "\n";
    }
    return 0;
}