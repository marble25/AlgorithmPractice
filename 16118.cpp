//
// Created by marble on 20. 10. 11..
//

// 벨만 포드를 priority_queue로 시도해서 시간초과가 나온 문제
// 정확하게 알고리즘을 숙지해야 한다.

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
vector<pair<int, int>> linked[4005];

long long dis_wolf[4005][2] = {0};
long long dis_fox[4005] = {0};

const long long INF = 11109876543210;

queue<pair<long long, pair<int, int>>> q_wolf;
queue<pair<long long, int>> q_fox;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y, c;
        cin >> x >> y >> c;
        linked[x].push_back({y, c*2});
        linked[y].push_back({x, c*2});
    }

    for(int i=1;i<=n;i++) { // 거리를 최대값(연결 안됨)으로 초기화
        dis_wolf[i][0] = INF;
        dis_wolf[i][1] = INF;
        dis_fox[i] = INF;
    }

    // 여우는 일반적인 bellman-ford를 돌림
    dis_fox[1] = 0;
    q_fox.push({0, 1});

    while(!q_fox.empty()) {
        int x = q_fox.front().second;
        q_fox.pop();

        for(auto &it:linked[x]) {
            int next = it.first;
            long long cost = it.second;

            if(dis_fox[next] > dis_fox[x] + cost) {
                dis_fox[next] = dis_fox[x] + cost;
                q_fox.push({dis_fox[next], next});
            }
        }
    }

    // 늑대는 홀수 번째인지 짝수 번째인지를 확인하는 변수를 같이 넣음
    dis_wolf[1][0] = 0;
    q_wolf.push({0, {1, 0}});

    while(!q_wolf.empty()) {
        int x = q_wolf.front().second.first;
        int is_first = q_wolf.front().second.second;
        q_wolf.pop();

        for(auto &it:linked[x]) {
            int next = it.first;
            long long cost = (is_first == 0 ? it.second / 2 : it.second * 2); // 홀수 번째이면 2를 나누고, 짝수 번째이면 2를 곱함

            if(dis_wolf[next][1-is_first] > dis_wolf[x][is_first] + cost) {
                dis_wolf[next][1-is_first] = dis_wolf[x][is_first] + cost;
                q_wolf.push({dis_wolf[next][1-is_first], {next, 1-is_first}});
            }
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++) {
        if(dis_wolf[i][0] > dis_fox[i] && dis_wolf[i][1] > dis_fox[i]) { // 늑대 두 경우보다 여우가 더 빠르면 개수 증가
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}