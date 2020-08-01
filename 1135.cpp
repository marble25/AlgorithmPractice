//
// Created by marble on 20. 8. 1..
//

// 쉽사리 이해가 가지 않는 문제이다.
// 그리디 전략을 어떻게 짜야 할지 감이 잘 안왔다.

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

int n;
vector<pair<int, int>> vc[55];

bool comp(const pair<int, int> a, const pair<int, int> b) {
    return a.first > b.first;
}

int dfs(int here) {
    int ret = 0;
    for(int i=0;i<vc[here].size();i++) { // 자기 아래 노드들의 비용을 모두 구함
        int next = vc[here][i].second;
        vc[here][i].first = 1 + dfs(next);
    }

    sort(vc[here].begin(), vc[here].end(), comp); // 비용이 큰 순서대로 정렬

    for(int i = 0;i<vc[here].size();i++) { // 최대 비용을 구함
        vc[here][i].first += i;
        ret = max(ret, vc[here][i].first);
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        if(val != -1) {
            vc[val].push_back({0, i});
        }
    }


    cout << dfs(0);

    return 0;
}