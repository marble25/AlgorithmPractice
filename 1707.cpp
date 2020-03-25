//
// Created by marble on 20. 3. 25..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

const int MAX = 20001;

vector<int> linked[MAX];
int visited[MAX];

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1; // 처음 시작해보는 노드의 visit를 1로 설정
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int & there : linked[here]) {
            if(visited[there] == 0) { // there을 방문 안했으면 here과 다른 집합으로 넣어줌
                q.push(there);
                visited[there] = 3-visited[here];
            } else if(visited[there] == visited[here]) { // here과 인접한데도 visit가 같은 노드라면(다른 집합이어야 하는데 같다면)
                return false;
            }
        }
    }

    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;
    while(k--) {
        int v, e;
        cin >> v >> e;

        // 초기화해주기
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<MAX;i++) {
            linked[i].clear();
        }

        for(int i=0;i<e;i++) {
            int x, y;
            cin >> x >> y;
            linked[x].push_back(y); // x와 y를 연결해줌
            linked[y].push_back(x);
        }

        bool can_make_graph = true;

        for(int i=1;i<=v;i++) {
            if(visited[i] == 0) { // 방문 안해본 노드라면 bfs 시작
                can_make_graph = bfs(i);
                if(!can_make_graph) {
                    cout << "NO\n";
                    break;
                }
            }
        }

        if(can_make_graph) {
            cout << "YES\n";
        }
    }
    return 0;
}