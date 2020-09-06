//
// Created by marble on 20. 9. 6..
//

// 처음에는 조금 난해했는데 모든 선거구 조합에 대해서 bfs를 통해 연결성 확인하면 풀리는 문제이다.
// 시간 초과 생각해서 복잡한 알고리즘을 쓰려 했는데 생각보다 짧게 나온다.

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
int people[15] = {0};
vector<int> linked[15];

int total = 0; // 전체 총합
int added = 0; // 그룹 1의 총합
int group[15] = {0}; // 그룹 1이면 1, 그룹 2면 0
int ans = 987654321;

bool bfs(int team, int x, int len) { // bfs로 연결 여부 확인
    int visited[15] = {0};
    queue<int> q;

    visited[x] = 1;
    q.push(x);
    len--;

    while(!q.empty()) {
        x = q.front();
        q.pop();

        for(auto &it:linked[x]) {
            if(group[it] == team && visited[it] == 0) { // team에 속해 있고 방문을 안했으면
                visited[it] = 1;
                q.push(it);
                len--;
            }
        }
    }

    return (len == 0); // 총 방문한 개수가 len이면(그 그룹을 모두 방문)
}

void check(int len) {
    int start1 = 1;
    int start2 = 0;
    for(int i=1;i<=n;i++) { // 그룹 2의 시작점 찾기
        if(group[i] == 0) {
            start2 = i;
            break;
        }
    }

    if(start2 == 0) return; // 그룹 2가 존재하지 않으면 return

    if(bfs(1, start1, len) && bfs(0, start2, n-len)) { // 그룹 1도 모두 연결되어 있고 그룹 2도 모두 연결되어 있으면
        ans = min(ans, abs(added - (total - added))); // 둘의 차이를 답으로 채택
    }
}

void select(int x, int len) { // 그룹을 선택하는 부분
    check(len);
    for(int i=x+1;i<=n;i++) { // 하나씩 포함시키거나 빼고 진행
        group[i] = 1;
        added += people[i]; // 그룹 1의 총합
        select(i, len+1);
        group[i] = 0;
        added -= people[i];
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> people[i];
        total += people[i];
    }

    for(int i=1;i<=n;i++) {
        int x, y;
        cin >> x;
        for(int j=0;j<x;j++) {
            cin >> y;
            linked[i].push_back(y);
        }
    }

    group[1] = 1;
    added = people[1];
    select(1, 1); // 1번 선거구는 무조건 그룹 1로 설정해서 시작

    if(ans == 987654321) cout << -1;
    else cout << ans;

    return 0;
}