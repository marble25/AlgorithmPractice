//
// Created by marble on 20. 4. 21..
//

// 흠.. 간단한 bfs로 풀었는데 런타임 에러가 나서 보았더니
// array index out of bound였다..
// 배열값 초과는 생각 못했다..

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
vector<int> linked[110];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y);
    }
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y);
    }

    queue<int> q;
    int visited[110] = {0};

    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int x = q.front();
        if(x == 100) break;
        q.pop();

        for(int i=1;i<=6;i++) {
            if(!linked[x+i].empty()) { // 사다리나 뱀으로 연결되어 있으면
                int linked_node = linked[x+i][0];
                if(visited[linked_node] == 0) { // 방문 안했으면 queue에 push
                    q.push(linked_node);
                    visited[linked_node] = visited[x] + 1;
                }
            } else if(visited[x+i] == 0) { // 연결 안되어 있고 방문 안했으면 queue에 push
                q.push(x+i);
                visited[x+i] = visited[x] + 1;
            }
        }
    }

    cout << visited[100] - 1 << "\n";

    return 0;
}