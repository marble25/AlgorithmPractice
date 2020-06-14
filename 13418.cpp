//
// Created by marble on 20. 6. 15..
//

// 문제가 어이가 없다...
// 오르막길이 가중치 1인 것처럼 해놓더니...
// 내리막길이 가중치 1이다...
// 알고리즘 자체는 Kruskal로 쉽게 풀었다.

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
vector<pair<int, pair<int, int>>> linked;

int parent[1005] = {0};
int rnk[1005] = {0};

void init() {
    for(int i=0;i<=n;i++) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

int root(int x) {
    int y = parent[x];
    while(y != parent[y]) {
        y = parent[y];
    }
    parent[x] = y;
    return y;
}

int merge(int x, int y) {
    x = root(x);
    y = root(y);

    if(x == y) return 0;
    else {
        if(rnk[x] < rnk[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
        }

        if(rnk[x] == rnk[y]) {
            rnk[x] ++;
        }
        return 1;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int min_cost=0, max_cost=0;
    for(int i=0;i<=m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        z = 1-z;
        if(i == 0) {
            min_cost += z;
            max_cost += z;
            continue;
        }
        linked.push_back({z, {x, y}});
    }
    sort(linked.begin(), linked.end());

    init();
    for(int i=0;i<m;i++) {
        int z = linked[i].first, x = linked[i].second.first, y = linked[i].second.second;
        if(merge(x, y) == 1) {
            min_cost += z;
        }
    }

    init();
    for(int i=m-1;i>=0;i--) {
        int z = linked[i].first, x = linked[i].second.first, y = linked[i].second.second;
        if(merge(x, y) == 1) {
            max_cost += z;
        }
    }

    cout << max_cost * max_cost - min_cost * min_cost;


    return 0;
}