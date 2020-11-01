//
// Created by marble on 20. 11. 1..
//

// stack에 추가해서 역순으로 출력해야 하는데, 정방향으로 출력해서 어이없이 틀린 문제
// 항상 검토하는 습관을 들여야겠다.

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

int t;
int a, b;

pair<int, char> parent[10005];
queue<int> q;
int visited[10005];

void bfs(int x) {
    while(!q.empty()) { // 큐 초기화
        q.pop();
    }

    q.push(x);
    visited[x] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        int d = (x * 2) % 10000; // 2배
        int s = (x - 1 + 10000) % 10000; // -1
        int l = (x / 1000) + (x % 1000) * 10; // 왼쪽 시프트
        int r = (x / 10) + (x % 10) * 1000; // 오른쪽 시프트

        // 방문 안했으면, 부모 노드에 삽입하고, 방문 체크하고, 큐에 넣는다.
        if(!visited[d]) {
            parent[d] = {x, 'D'};
            visited[d] = 1;
            q.push(d);
        }

        if(!visited[s]) {
            parent[s] = {x, 'S'};
            visited[s] = 1;
            q.push(s);
        }

        if(!visited[l]) {
            parent[l] = {x, 'L'};
            visited[l] = 1;
            q.push(l);
        }

        if(!visited[r]) {
            parent[r] = {x, 'R'};
            visited[r] = 1;
            q.push(r);
        }

        if(d == b || s == b || l == b || r == b) { // 목적지라면 리턴
            return;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        cin >> a >> b;

        memset(visited, 0, sizeof(visited));

        bfs(a);

        stack<char> stk;
        while(b != a) { // a가 될 때까지 부모를 타고 올라감 / 저장
            stk.push(parent[b].second);
            b = parent[b].first;
        }

        while(!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }

        cout << "\n";
    }
    return 0;
}