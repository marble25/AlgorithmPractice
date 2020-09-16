//
// Created by marble on 20. 9. 16..
//

// 제자리에 서 있을 수 있었다니...
// 시간에 대한 고려를 추가한 BFS를 통해 쉽게 풀 수 있었다.

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

char board[10][10][10] = {0};
int visited[10][10][10] = {0};

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<8;i++) {
        cin >> board[0][i];
    }

    for(int k=1;k<=8;k++) { // 시간 변화에 따른 벽 변화도 미리 만들어둠
        for(int i=0;i<7;i++) {
            for(int j=0;j<8;j++) {
                board[k][i+1][j] = board[k-1][i][j];
            }
        }
        for(int j=0;j<8;j++) {
            board[k][0][j] = '.';
        }
    }

    queue<pair<int, pair<int, int>>> q;

    visited[0][7][0] = 1;
    q.push({0, {7, 0}});

    while(!q.empty()) {
        int time = q.front().first;
        int x = q.front().second.first, y = q.front().second.second;
        q.pop();

        if(time == 8 || (x == 0 && y == 7)) { // 8턴 동안 버티거나(8턴 버티면 벽이 모두 없어짐), 끝에 도달했다면 1 출력
            cout << 1;
            return 0;
        }

        for(int i=0;i<9;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 0 || my < 0 || mx >= 8 || my >= 8) continue;

            // 방문할 위치를 이미 방문했거나, 방문할 위치가 현재 벽이거나 다음 턴에 벽이 되는 경우 continue
            if(visited[time+1][mx][my] != 0 || board[time][mx][my] == '#' || board[time+1][mx][my] == '#') continue;

            visited[time+1][mx][my] = 1;
            q.push({time+1, {mx, my}});
        }
    }

    cout << 0;

    return 0;
}