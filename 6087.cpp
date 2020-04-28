//
// Created by marble on 20. 4. 28..
//

// 어렵지 않은 문제였지만 문제를 살짝 잘못 생각해서 한번 틀린 문제
// parent 노드를 어디에 저장하고, 값을 어떻게 카운트하는지 방법을 바꾸니 맞춘 문제

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

int w, h;
char map[105][105] = {0};
queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
int visited[105][105] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> w >> h;
    pair<int, int> start, end;

    start = {-1, -1};

    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            cin >> map[i][j];
            if(map[i][j] == 'C') {
                if(start.first == -1 && start.second == -1) { // start가 비어있으면 start에 대입
                    start = {i, j};
                } else {
                    end = {i, j};
                }
            }
        }
    }

    q.push({{{-1, -1}, start}, 0});
    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        pair<int, int> past = q.front().first.first, cur = q.front().first.second;
        int cnt = q.front().second; // 이전까지 거울의 카운트
        q.pop();

        for(int i=0;i<4;i++) {
            int moved_x = cur.first + dx[i];
            int moved_y = cur.second + dy[i];

            if(map[moved_x][moved_y] == '.' || map[moved_x][moved_y] == 'C') {
                int adder = !((past.first + dx[i] == cur.first) && (past.second + dy[i] == cur.second)); // 거울을 추가해야 하는지
                if(visited[moved_x][moved_y] == 0) visited[moved_x][moved_y] = 987654321;
                if(visited[moved_x][moved_y] >= cnt + adder) { // 이전에 있던 값이 현재 거울 갯수보다 크거나 같으면 queue에 추가
                    q.push({{{cur.first, cur.second}, {moved_x, moved_y}}, cnt+adder});
                    visited[moved_x][moved_y] = cnt + adder;
                }
            }
        }
    }

    cout << visited[end.first][end.second]-1; // 처음 값이 1이었으므로 하나 뺌

    return 0;
}