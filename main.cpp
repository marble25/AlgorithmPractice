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

int n;
vector<pair<int, int>> assign;
int parent[200005] = {0};

int find_root(int x) {
    int y = parent[x];
    while(y != parent[y]) {
        y = parent[y];
    }
    parent[x] = y;
    return y;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        assign.push_back({y, x});
    }
    sort(assign.begin(), assign.end(), greater<>());

    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }

    int ans = 0;

    for(auto &it:assign) {
        int cup = it.first, dead = it.second;

        int root = find_root(dead);
        if(root != 0) {
            ans += cup;
            parent[root] = find_root(root-1);
        }
    }

    cout << ans;

    return 0;
}