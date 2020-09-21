//
// Created by marble on 20. 9. 21..
//

// 위상 정렬을 이용해서 오랜만에 문제를 풀어 보았다.
// 중간에 뭔가 꼬여서 생각보다는 오래 걸렸던 문제

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
int needed[105][105] = {0}; // 필요한 기본 블럭의 수
vector<pair<int, int>> linked[105]; // 연결된 상태 표현
int parent[105] = {0}; // 진입차수 배열

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y, k;
        cin >> x >> y >> k;
        linked[y].push_back({x, k});
        parent[x]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(parent[i] == 0) { // 진입차수가 0이면 queue에 넣고 기본 블럭의 수를 세팅
            needed[i][i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto &it:linked[x]) { // 연결된 다음 블럭들 순회
            for(int i=1;i<=n;i++) { // 자기 자신이 가지고 있는 기본 블럭을 다음 블럭에다 더해줌
                needed[it.first][i] += needed[x][i] * it.second;
            }

            parent[it.first]--; // 다음 블럭의 진입 차수 감소
            if(parent[it.first] == 0) { // 다읍 블럭 진입 차수가 0이면 queue에 넣음
                q.push(it.first);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(needed[n][i] != 0) {
            cout << i << " " << needed[n][i] << "\n";
        }
    }
}