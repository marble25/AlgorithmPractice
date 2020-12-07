//
// Created by marble on 20. 12. 7..
//

// 시간초과의 늪에서 계속 헤맨 문제
// 어렵지 않았는데 너무 무식하게 풀었던 것 같다.
// 해당 플레이어마다 큐를 잡아주는 것이 색달랐던 문제

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

int n, m, p;
int s[1005] = {0};
char in[1005];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int mp[1005][1005] = {0};

int castle[1005] = {0};
queue<pair<int, int>> territory[1005]; // 해당 플레이어마다 큐를 잡아줌


void bfs() {
    while(true) {
        bool flag = false;
        for(int player=1;player<=p;player++) { // 각각의 플레이어마다 영토 확장의 기회를 줌
            for(int r=0;r<s[player];r++) { // 해당 range만큼의 영토 확장
                int sz = territory[player].size(); // 현재 들어가 있는 queue만큼만 확장(이번 턴에)
                if(sz == 0) break;

                for(int k=0;k<sz;k++) {
                    int x = territory[player].front().first, y = territory[player].front().second;
                    territory[player].pop();

                    for(int i=0;i<4;i++) {
                        int mx = x + dx[i], my = y + dy[i];
                        if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
                        if(mp[mx][my] != 0) continue;

                        mp[mx][my] = player;
                        territory[player].push({mx, my});
                        flag = true; // 하나라도 확장되었으면 다음번도 체크해야함
                        castle[player]++; // 성 개수 증가
                    }
                }
            }
        }

        if(!flag) break; // 확장이 하나도 안되면 break
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> p;
    for(int i=1;i<=p;i++) {
        cin >> s[i];
    }

    for(int i=0;i<n;i++) {
        cin >> in;
        for(int j=0;j<m;j++) {
            mp[i][j] = (in[j] == '.' ? 0 : (in[j] == '#' ? -1 : in[j] - '0'));
            if(mp[i][j] > 0) { // 해당 플레이어 성 개수 설정
                territory[mp[i][j]].push({i, j});
                castle[mp[i][j]]++;
            }
        }
    }

    bfs();

    for(int i=1;i<=p;i++) {
        cout << castle[i] << " ";
    }

    return 0;
}