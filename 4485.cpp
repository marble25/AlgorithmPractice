//
// Created by 이지호 on 21. 2. 10..
//

// dijkstra를 이용한 간단한 문제

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
int arr[130][130] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    int visited[130][130] = {0};

    for(int i=0;i<130;i++) {
        for(int j=0;j<130;j++) {
            visited[i][j] = 987654321;
        }
    }

    int x = 1, y = 1;
    visited[x][y] = arr[x][y];
    pq.push({-visited[x][y], {x, y}});
    while(!pq.empty()) {
        x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        for(int i=0;i<4;i++){
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 1 || my < 1 || mx > n | my > n) continue;
            if(visited[x][y] + arr[mx][my] < visited[mx][my]) {
                visited[mx][my] = visited[x][y] + arr[mx][my];
                pq.push({-visited[mx][my], {mx, my}});
            }
        }
    }

    return visited[n][n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int k=1;;k++) {
        cin >> n;
        if(n == 0) break;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cin >> arr[i][j];
            }
        }
        printf("Problem %d: %d\n", k, dijkstra());
    }

    return 0;
}