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
vector<pair<int, int>> linked[1005];
int parent[1005] = {0};


int st, en;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y, c;
        cin >> x >> y >> c;
        linked[x].push_back({y, c});
    }
    cin >> st >> en;

    int dis[1005];

    memset(parent, -1, sizeof(parent));
    fill(dis, dis+1005, 987654321);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    dis[st] = 0;
    q.push({0, st});

    while(!q.empty()) {
        int cost = q.top().first, x = q.top().second;
        q.pop();

        if(dis[x] < cost) continue;

        for(int i=0;i<linked[x].size();i++) {
            int next = linked[x][i].first;
            int next_cost = linked[x][i].second + cost;

            if(dis[next] > next_cost) {
                dis[next] = next_cost;

                parent[next] = x;
                q.push({next_cost, next});
            }
        }
    }

    stack<int> stk;

    int x = en;
    while(x != -1) {
        stk.push(x);
        x = parent[x];
    }

    cout << dis[en] << '\n';
    cout << stk.size() << '\n';

    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    return 0;
}