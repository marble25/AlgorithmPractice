//
// Created by marble on 20. 9. 15..
//

// 요즘 자꾸 실수를 하는게 마음이 급해서인지 잘 모르겠다.
// 문제를 무조건 꼼꼼히 푸는 연습을 해야한다.

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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char in[12][10];
int visited[12][6] = {0};
queue<pair<int, int>> q;


int bfs(int x, int y) {
    stack<pair<int, int>> st; // 뿌요뿌요 연결된 좌표들

    visited[x][y] = 1;
    q.push({x, y});
    st.push({x, y});

    while(!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 0 || my < 0 || mx >= 12 || my >= 6) continue; // 범위 밖이면 넘어감
            if(visited[mx][my] == 1 || in[mx][my] != in[x][y]) continue; // 이미 방문했거나 색이 다르면 넘어감
            q.push({mx, my});
            visited[mx][my] = 1;
            st.push({mx, my});
        }
    }

    if(st.size() >= 4) { // 연결된 것이 4가 넘으면
        while(!st.empty()) { // 연결된 좌표들 터뜨림
            x = st.top().first, y = st.top().second;
            st.pop();

            in[x][y] = '.';
        }
        return 1;
    }

    return 0;
}

void gravity() { // 중력 적용
    for(int j=0;j<6;j++) {
        int prev = 12; // 이전에 블럭이 있던 위치(초기는 밑바닥보다 아래)
        for(int i=11;i>=0;i--) {
            if(in[i][j] != '.') { // .이 아니면
                if(prev-1 != i) { // 밑바닥과 현 위치 사이에 간격이 있으면
                    in[prev-1][j] = in[i][j]; // 현 위치 값을 밑바닥 바로 위로 당겨옴
                    in[i][j] = '.'; // 현 위치를 .으로 바꿈
                }
                prev--; // 밑바닥이 한 칸 올라감
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<12;i++) {
        cin >> in[i];
    }
    int ans = 0;
    while(true) {
        int count = 0;
        memset(visited, 0, sizeof(visited));
        for(int j=0;j<6;j++) {
            for(int i=11;i>=0;i--) {
                if(in[i][j] == '.') continue;
                if(visited[i][j] == 1) continue;
                count = max(count, bfs(i, j)); // count가 최대 1개 올라감
            }
        }
        gravity();

        if(count == 0) break; // count가 0이면 끝
        ans += count;
    }

    cout << ans;

    return 0;
}