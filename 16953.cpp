//
// Created by marble on 20. 10. 5..
//

// 간단한 bfs 문제
// 다만 범위가 커서 배열 형태의 visited를 사용할 수 없었다

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

int a, b;
queue<pair<long long, int>> q;
map<long long, int> mp;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    q.push({a, 1});

    while(!q.empty()) {
        long long x = q.front().first;
        int dis = q.front().second;
        q.pop();

        if(x == b) {
            cout << dis;
            return 0;
        } else if(x > b) {
            continue;
        }

        if(mp.find(x * 10 + 1) == mp.end()) {
            q.push({x * 10 + 1, dis+1});
            mp.insert({x * 10 + 1, 1});
        }

        if(mp.find(x*2) == mp.end()) {
            q.push({x * 2, dis+1});
            mp.insert({x*2, 1});
        }


    }

    cout << -1;

    return 0;
}