//
// Created by marble on 20. 12. 8..
//

// 이분 매칭을 오랜만에 다시 풀어본 문제
// 구조적인 부분을 이해를 다시 해야겠다.

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

int n, m;
vector<int> l[205];

int visited[205] = {0};
int room[205] = {0};

int dfs(int x) {
    for(int i=0;i<l[x].size();i++) {
        int num = l[x][i];
        if(visited[num]) continue;
        visited[num] = 1;

        if(room[num] == 0 || dfs(room[num])) {
            room[num] = x;
            return 1;
        }
    }

    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int sz;
        cin >> sz;

        for(int j=0;j<sz;j++) {
            int x;
            cin >> x;
            l[i].push_back(x);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        memset(visited, 0, sizeof(visited));
        if(dfs(i)) ans++;
    }

    cout << ans;
    return 0;
}