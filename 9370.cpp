//
// Created by marble on 20. 3. 24..
//

// 사소한 부분을 엄청 많이 틀렸던 문제
// 한번 할 때 제대로 해야겠다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

int n, m, t;
int s, g, h;

vector<vector<pair<int, int>>> v;
vector<int> candidates;

void bfs(int start, int dis[]) {
    for(int i=1;i<=n;i++) {
        dis[i] = 987654321;
    }
    dis[start] = 0;

    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto it=v[x].begin();it != v[x].end();it++) {
            int next_node = (*it).first;
            if(dis[next_node] > dis[x] + (*it).second) {
                q.push(next_node);
                dis[next_node] = dis[x] + (*it).second;
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        v.clear();
        candidates.clear();

        v.resize(n+1, vector<pair<int, int>>());

        int a, b, d, x;
        int gh = 0;
        for(int i=0;i<m;i++) {
            cin >> a >> b >> d;
            v[a].push_back(make_pair(b, d));
            v[b].push_back(make_pair(a, d));
            if((a == g && b == h) || (a == h && b == g)) gh = d; // g와 h사이의 거리를 저장해 놓음
        }
        for(int i=0;i<t;i++) {
            cin >> x;
            candidates.push_back(x);
        }

        vector<int> result;
        int dis1[2001], dis_g[2001], dis_h[2001];

        bfs(s, dis1); // s에서 각 정점까지의 최단거리를 구함
        bfs(g, dis_g); // g에서 각 정점까지 최단거리를 구함
        bfs(h, dis_h); // h에서 각 정점까지 최단거리를 구함
        for(int & candidate : candidates) {
            if(dis1[g] + gh + dis_h[candidate] == dis1[candidate] ||
               dis1[h] + gh + dis_g[candidate] == dis1[candidate]) { // s->g->h->후보지 또는 s->h->g->후보지가 s->후보지의 거리와 같을 때
                result.push_back(candidate);
            }
        }
        sort(result.begin(), result.end());
        for(int & it : result) {
            cout << it << ' ';
        }
        cout << '\n';
    }

    return 0;
}