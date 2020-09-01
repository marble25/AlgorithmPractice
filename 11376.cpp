//
// Created by marble on 20. 9. 1..
//

// 예전에 배웠던 이분 매칭으로 풀어보았는데
// 너무 시간이 오래 걸린다
// 시간을 줄여봐야겠다

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
vector<int> v[1005];

int parent[1005] = {0};
bool visited[1005];

int cnt = 0;

bool dfs(int x) {
    for(int i=0;i<v[x].size();i++) {
        int t = v[x][i];

        if(visited[t]) continue;
        visited[t] = true;

        if(parent[t] == 0 || dfs(parent[t])) {
            parent[t] = x;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int x, y;
        cin >> x;
        for(int j=0;j<x;j++) {
            cin >> y;
            v[i].push_back(y);
        }
    }

    fill(parent, parent + 1005, 0);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<2;j++) {
            fill(visited, visited + 1005, false);
            if(dfs(i)) cnt++;
        }
    }

    cout << cnt;

    return 0;
}