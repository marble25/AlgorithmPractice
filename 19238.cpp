//
// Created by marble on 20. 10. 10..
//

// 너무 조건이 많아서 짜증났던 문제

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

int n, m, l;
int mp[25][25] = {0};
pair<int, int> start;
vector<pair<pair<int, int>, pair<int, int>>> v;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

// e_x와 e_y가 -1 : 다음 택시 승객 찾기
// 아니면 : 승객 태우고 목적지로(e_x와 e_y가 목적지)
pair<pair<int, int>, pair<int, int>> findNext(int s_x, int s_y, int e_x, int e_y) {
    int visited[25][25] = {0};

    queue<pair<int, int>> q;
    q.push({s_x, s_y});
    visited[s_x][s_y] = 1;

    while(!q.empty()) { // 전체를 BFS 돌림
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 1 || my < 1 || mx > n || my > n) continue;
            if(mp[mx][my] == -1 || visited[mx][my] != 0) continue;

            q.push({mx, my});
            visited[mx][my] = visited[x][y] + 1;
        }
    }
    int mn = 987654321;
    int mx = -1, my = -1, rx = -1, ry = -1;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(mp[i][j] == -1 || visited[i][j] == 0) continue; // 해당사항 없는 애들 걸러냄
            if((e_x == -1 && e_y == -1) && mp[i][j] != 0) { // 승객이 있으면
                if(visited[i][j] < mn) { // 가장 거리가 낮으면 가져옴
                    mn = visited[i][j];

                    mx = i;
                    my = j;

                    rx = v[mp[i][j] - 1].second.first;
                    ry = v[mp[i][j] - 1].second.second;
                }
            } else if(i == e_x && j == e_y) { // 승객의 목적지라면
                mn = visited[i][j];

                mx = i;
                my = j;
            }
        }
    }

    l -= (mn - 1); // 거리만큼 기름 빼줌
    if(mx != -1 && my != -1 && e_x == -1 && e_y == -1) { // 다음 승객이 있으면 그 승객 출발지를 초기화
        mp[mx][my] = 0;
    }


    return {{mx, my}, {rx, ry}};
}

void process() {
    pair<pair<int, int>, pair<int, int>> result = {start, {-1, -1}};

    for(int i=0;i<m;i++) {
        result = findNext(result.first.first, result.first.second, -1, -1);

        if(result.first.first == -1) { // 못찾으면 -1
            cout << -1;
            return;
        }

        int temp = l;
        result = findNext(result.first.first, result.first.second, result.second.first, result.second.second);

        if(result.first.first == -1) { // 못찾으면 -1
            cout << -1;
            return;
        }

        if(l < 0) { // 기름 없으면 -1
            cout << -1;
            return;
        } else { // 태운 승객의 거리 * 2
            int consumption = temp - l;
            l += (consumption * 2);
        }
    }

    cout << l;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> l;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> mp[i][j];
            mp[i][j] = -mp[i][j];
        }
    }

    cin >> start.first >> start.second;

    for(int i=0;i<m;i++) {
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;
        v.push_back({{s_x, s_y}, {e_x, e_y}});

        mp[s_x][s_y] = i+1;
    }

    process();

    return 0;
}