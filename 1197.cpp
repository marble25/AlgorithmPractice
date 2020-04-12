//
// Created by marble on 20. 4. 12..
//

// mst의 크루스칼 알고리즘을 이용해서 풀었다.
// union find에 대해, 크루스칼 알고리즘에 대해 숙지해야겠다.

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

int v, e;
vector<pair<int, pair<int, int>>> edge;
int parent[10005] = {0};
int height[10005] = {0};

void init() {
    for(int i=1;i<=v;i++) {
        parent[i] = -1;
        height[i] = 0;
    }
}

int find_root(int x) {
    if(parent[x] == -1) return x;
    return find_root(parent[x]);
}

bool is_same_set(int x, int y) {
    return (find_root(x) == find_root(y));
}

void merge(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if(x == y) return;
    if(height[x] < height[y]) swap(x, y);
    parent[y] = x; // 병합
    if(height[x] == height[y]) height[x]++; // 높이 같으면 높이 증가
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    for(int i=0;i<e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }

    int ans = 0;
    init();
    sort(edge.begin(), edge.end());
    for(auto &it:edge) {
        if(!is_same_set(it.second.first, it.second.second)) { // 같은 집합이 아니면 병합하고 연결하는데 드는 비용을 추가
            ans += it.first;
            merge(it.second.first, it.second.second);
        }
    }
    cout << ans;
    return 0;
}