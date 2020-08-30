//
// Created by marble on 20. 8. 30..
//

// 한번에 풀기는 했지만 생각보다 고생고생했던 문제
// combination logic을 구현하는데 오래 걸렸던 문제
// permutation을 이용한 combination은 잘 알아둬야겠다.

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

int n, m;
int mp[55][55] = {0};
int max_virus;
vector<pair<int, int>> st_point;

int visited[55][55] = {0};
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 987654321;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int mx = x+dx[i], my = y+dy[i];
            if(mx < 1 || my < 1 || mx > n || my > n) continue; // 맵을 넘어가면 continue
            if(mp[mx][my] == 1 || visited[mx][my] != 0) continue; // 벽이거나 방문한 적이 있으면 continue
            visited[mx][my] = visited[x][y] + 1;
            q.push({mx, my});
        }
    }

    int temp = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(mp[i][j] != 1) { // 벽이 아니면
                if(visited[i][j] == 0) return; // 방문한 적이 없는 노드가 있으면 정답이 될 수 없음
                temp = max(visited[i][j], temp); // 방문한 거리 중 가장 긴 시간을 찾음
            }
        }
    }

    ans = min(ans, temp); // 최대 시간이 가장 짧은 것이 정답
}

void select() {
    max_virus = st_point.size();

    vector<int> v;
    vector<bool> sv(max_virus);

    for(int i=0;i<max_virus;i++) { // 인덱스를 벡터로 채워넣음
        v.push_back(i);
    }
    fill(sv.end()-m, sv.end(), true); // 끝에 m개를 true로 설정 -> 앞에 max_virus-m개는 false, 뒤에 m개는 true
    do {
        for(int i=0;i<max_virus;i++) {
            if(sv[i]) { // sv가 true일 때만 선택
                q.push(st_point[i]);
                visited[st_point[i].first][st_point[i].second] = 1;
            }
        }

        bfs();
        memset(visited, 0, sizeof(visited)); // visited 초기화
    } while(next_permutation(sv.begin(), sv.end())); // sv를 계속 섞음(permutation)
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 2) { // 시작 지점으로 가능한 것을 vector에 넣음
                st_point.push_back({i, j});
            }
        }
    }

    select();

    if(ans == 987654321) cout << -1;
    else cout << ans - 1;

    return 0;
}