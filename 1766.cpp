//
// Created by marble on 20. 6. 5..
//

// 위상정렬을 이용해서 간단하게 풀이한 문제

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

int n, m;
vector<int> linked[32005];
int order[32005] = {0};
vector<int> ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y); // 연결 리스트 설정
        order[y]++; // 이 문제를 풀기 전에 있어야 하는 문제의 개수 증가
    }

    priority_queue<int> pq;
    for(int i=1;i<=n;i++) {
        if(order[i] == 0) pq.push(-i); // 이전에 풀어야 하는 문제가 하나도 없으면 push
    }

    while(!pq.empty()) {
        int x = -pq.top();
        pq.pop();

        ans.push_back(x); // answer에 꾸준히 넣어줌

        for(auto &it:linked[x]) {
            order[it] --; // 이 문제 다음으로 풀어야하는 문제의 (앞에 풀어야 하는 문제 수) 감수
            if(order[it] == 0) pq.push(-it); // 앞에 풀어야 하는 문제가 없으면 push
        }
    }

    for(auto &it:ans) {
        cout << it << " ";
    }

    return 0;
}