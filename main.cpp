// 벨만 포드로 풀어보았는데
// 단순 Distance 기반 BFS가 더 빠르다.

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

int n, m;
vector<pair<int, int>> linked[505];

long long dis[505];
int cnt[505] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        linked[x].push_back({y, z});
    }
    fill(dis, dis+505, INT32_MAX); // distance 초기화

    queue<int> q;

    q.push(1);
    dis[1] = 0;

    while(!q.empty()) {
        int start = q.front();
        if(cnt[start] >= n) { // 무한 루프를 막기 위해 어떤 정점을 n번 이상 방문했다면 끝냄
            cout << -1;
            return 0;
        }
        q.pop();

        for(auto& it:linked[start]) {
            int next = it.first;
            long long d = it.second;
            if(dis[next] > dis[start] + d) { // 더 작은 값으로 방문할 수 있다면
                dis[next] = dis[start] + d;
                q.push(next);
                cnt[next] = cnt[start] + 1; // 이전 정점에 1을 더한 값을 next 정점에 저장
            }
        }
    }

    for(int i=2;i<=n;i++) {
        if(dis[i] == INT32_MAX) cout << -1 << "\n";
        else cout << dis[i] << "\n";
    }

    return 0;
}