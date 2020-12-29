//
// Created by marble on 20. 12. 30..
//

// 생각보다 까다로운 문제

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
queue<int> d[3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        d[x%3].push(x); // 3의 나머지 배열에 넣음
    }

    if(d[0].size() > (n+1)/2 || (d[0].empty() && !d[1].empty() && !d[2].empty())) { // 0이 너무 많거나(절반 이상), 0이 비어있는데 1과 2가 남아있으면 -1
        cout << -1;
        return 0;
    }

    while(!d[1].empty()) {
        if(d[0].size() > 1) { // 0이 1개 이상은 남아야 함(1과 2의 중간)
            cout << d[0].front() << ' ';
            d[0].pop();
        }
        cout << d[1].front() << ' ';
        d[1].pop();
    }

    if(!d[0].empty()) { // 0이 남아 있으면 1과 2에 끼워넣음
        cout << d[0].front() << ' ';
        d[0].pop();
    }

    while(!d[2].empty()) {
        cout << d[2].front() << ' ';
        d[2].pop();
        if(d[0].size()) { // 0이 남아있으면 사이사이에 0 끼워넣음
            cout << d[0].front() << ' ';
            d[0].pop();
        }
    }



    return 0;
}