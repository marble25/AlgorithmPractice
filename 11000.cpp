//
// Created by marble on 20. 11. 28..
//

// 문제를 잘못 읽어서 한번 틀린 문제

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

int n;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(v[0].second); // 첫 강좌의 끝나는 시간을 넣음

    for(int i=1;i<n;i++) {
        if(pq.top() <= v[i].first) { // 끝난 강좌가 있으면 강의실 비움
            pq.pop();
        }
        pq.push(v[i].second); // 강의실 채움
    }

    cout << pq.size();

    return 0;
}