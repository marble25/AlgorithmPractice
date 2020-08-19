//
// Created by marble on 20. 8. 20..
//

// DFS를 오램난에 사용하는 것 같다.
// 깔끔하게 풀 수 있었다.

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

int n, s, d;
vector<int> linked[100005];
int dis[100005] = {0};

int dfs(int node, int parent) {
    if(node != s && linked[node].size() == 1) { // leaf 노드라면 dis가 0이 되면서 리턴
        return dis[node] = 0;
    }

    for(int i=0;i<linked[node].size();i++) {
        int next = linked[node][i];
        if(next == parent) continue;
        dis[node] = max(dis[node], dfs(next, node) + 1); // dis는 자식 중 가장 긴 경로+1의 max를 가짐
    }

    return dis[node];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> d;
    for(int i=0;i<n-1;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y);
        linked[y].push_back(x);
    }

    int res = 0;
    dfs(s, 0);
    for(int i=1;i<=n;i++) {
        if(i != s && dis[i] >= d) { // 힘보다 남은 깊이가 크다면 무조건 방문을 해야 한다.
            res += 1;
        }
    }

    cout << res * 2;

    return 0;
}