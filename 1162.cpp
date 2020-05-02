//
// Created by marble on 20. 5. 2..
//

// 잔실수를 너무 많이 한 문제
// 잔실수를 줄여야 한다.
// 문제 자체는 다익스트라 + dp로 쉽게 풀렸다.

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

int n, m, k;
vector<pair<long long int, long long int>> v[10005];
priority_queue<pair<long long int, pair<long long int, long long int>>> pq;
bool visited[10005][25] = {false};
long long int dis[10005][25] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        long long int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }

    visited[1][0] = true;
    dis[1][0] = 0;
    pq.push({0, {0, 1}});

    while(!pq.empty()) {
        long long int covered = pq.top().second.first, x = pq.top().second.second;
        pq.pop();

        for(int i=0;i<v[x].size();i++) {
            int next = v[x][i].first, next_cost = v[x][i].second;
            if(!visited[next][covered] || (visited[next][covered] && dis[next][covered] > dis[x][covered] + next_cost)) {
                visited[next][covered] = true;
                dis[next][covered] = dis[x][covered] + next_cost;
                pq.push({-dis[next][covered], {covered, next}});
            }
            if(covered+1 > k) continue;
            if(!visited[next][covered+1] || (visited[next][covered+1] && dis[next][covered+1] > dis[x][covered])) {
                visited[next][covered+1] = true;
                dis[next][covered+1] = dis[x][covered];
                pq.push({-dis[next][covered+1], {covered+1, next}});
            }
        }
    }

    long long int mn = INT64_MAX;
    for(int i=0;i<=k;i++) {
        if(!visited[n][i]) continue;
        mn = min(mn, dis[n][i]);
    }

    cout << mn;

    return 0;
}