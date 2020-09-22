//
// Created by marble on 20. 9. 22..
//

// BFS를 이용해서 문제를 풀어 보았다.
// 칭찬이 중복될 수 있다는 점을 간과했다.

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

int n, m;
vector<int> linked[100005];
int praise[100005] = {0};
queue<int> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if(x != -1) linked[x].push_back(i); // 노드를 연결해줌
    }

    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        praise[x] += y; // 칭찬을 누적
    }

    q.push(1); // 사장에서 시작

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto &it:linked[x]) {
            praise[it] += praise[x]; // 사장의 직속 부하에게 칭찬을 모두 부여
            q.push(it); // 직속부하 queue에 추가
        }
    }

    for(int i=1;i<=n;i++) {
        cout << praise[i] << " ";
    }
}