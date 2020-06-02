//
// Created by marble on 20. 6. 3..
//

// 처음에 엉뚱하게 풀려고 하다가 뭔가 답이 이상해서 문제를 다시 보고 다시 푼 문제
// bfs라는 것을 쉽게 알 수 있었는데, 문제 이해를 제대로 하지 않고 풀어서 손해봤다.

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

int n;
int mp[25][25];
pair<int, int> shark;

int sz = 2, cnt = 0;
int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs(int x, int y) {
    queue<pair<int, int>> q;
    int visited[25][25] = {0};

    q.push({x, y});
    visited[x][y] = 1;

    int dis = 987654321;
    int next_x, next_y;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i];
            int my = y + dy[i];

            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(mp[mx][my] > sz) continue;
            if(visited[mx][my] != 0) continue;

            q.push({mx, my});
            visited[mx][my] = visited[x][y] + 1;

            if(mp[mx][my] != 0 && mp[mx][my] < sz) { // 자신보다 작은 물고기가 있으면
                if(dis > visited[mx][my]) { // 최소 거리면 먹음
                    dis = visited[mx][my];
                    next_x = mx;
                    next_y = my;
                } else if(dis == visited[mx][my]) { // 거리 같을 때
                    if(next_x > mx) { // 이전보다 위쪽이면 먹음
                        dis = visited[mx][my];
                        next_x = mx;
                        next_y = my;
                    } else if(next_x == mx) { // x좌표 같을 때
                        if(next_y > my) { // 왼쪽이면 먹음
                            next_x = mx;
                            next_y = my;
                        }
                    }
                } else {
                    break;
                }
            }
        }
    }

    if(dis != 987654321) { // 먹은 것이 있다면
        shark.first = next_x;
        shark.second = next_y;

        mp[next_x][next_y] = 0; // 먹은 물고기 초기화

        ans += (dis-1);
        cnt ++;

        if(cnt == sz) { // 자기 사이즈만큼 먹으면 업그레이드
            sz ++;
            cnt = 0;
        }
        return true;
    }
    return false;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 9) { // 상어 위치면 상어 좌표 설정
                shark.first = i;
                shark.second = j;
                mp[i][j] = 0; // 그 위치를 비워둠
            }
        }
    }

    while(bfs(shark.first, shark.second)); // fixed point까지 계속 먹음

    cout << ans;

    return 0;
}