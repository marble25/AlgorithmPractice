//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// deque의 사용법을 알아본 문제

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    deque<int> dq;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        dq.push_back(i);
    }
    int x;
    while(!dq.empty()) {
        x = dq.front();
        dq.pop_front();
        if(dq.empty()) {
            break;
        }
        x = dq.front();
        dq.pop_front();
        dq.push_back(x);
    }
    cout << x << '\n';
    return 0;
}