//
// Created by marble on 20. 9. 28..
//

// 간단하게 BFS를 돌려서 맞은 문제

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

int n, T;
vector<pair<int, int>> v;

int visited[50005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> T;
    v.push_back({0, 0}); // 시작점 추가
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }

    sort(v.begin(), v.end()); // y좌표 기준으로 정렬

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        int x = v[idx].second, y = v[idx].first;

        if(y == T) { // 끝에 도달했으면 종료
            cout << visited[idx]-1 << '\n';
            return 0;
        }

        for(int i=idx-1;i>=0;i--) { // 이전 좌표들을 검사
            int mx = v[i].second, my = v[i].first;
            if(abs(y-my) > 2) { // y좌표의 차이가 2를 초과한다면 더이상 검사할 필요 없음
                break;
            } else if(abs(y-my) <= 2 && abs(x-mx) <= 2 && visited[i] == 0) { // 기준을 충족하고 방문 안했으면
                q.push(i);
                visited[i] = visited[idx] + 1;
            }
        }

        for(int i=idx+1;i<=n;i++) {
            int mx = v[i].second, my = v[i].first;
            if(abs(y-my) > 2) { // y좌표의 차이가 2를 초과한다면 더이상 검사할 필요 없음
                break;
            } else if(abs(y-my) <= 2 && abs(x-mx) <= 2 && visited[i] == 0) { // 기준을 충족하고 방문 안했으면
                q.push(i);
                visited[i] = visited[idx] + 1;
            }
        }
    }

    cout << -1;
    return 0;
}