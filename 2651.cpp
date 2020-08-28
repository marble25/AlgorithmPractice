//
// Created by marble on 20. 8. 28..
//

// 그리디하게 풀어보았다.
// 예전에 푼 문제랑 비슷해서 쉽게 풀 수 있었다.

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

int max_dis;
int n;
int shop[110] = {0}; // 정비소 정비시간
int bet_dis[110] = {0}; // 정비소 사이 거리
long long cache[110] = {0}; // 해당 정비소의 최소 정비 시간
int parent[110] = {0}; // 해당 정비소 이전에 들른 정비소

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> max_dis;
    cin >> n;
    for(int i=0;i<n+1;i++) {
        cin >> bet_dis[i];
    }

    for(int i=1;i<=n;i++) {
        cin >> shop[i];
    }

    fill(cache, cache + 105, 10987654321); // 비용을 최대로 설정해놓음

    priority_queue<pair<long long, int>> pq; // 비용, idx

    pq.push({0, 0});
    parent[0] = -1;

    while(!pq.empty()) {
        long long cost = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        int sum_dis = 0;
        for(int i=1;idx+i<=n+1;i++) {
            int new_idx = idx+i; // idx에서 다이렉트로 방문할 정비소
            int new_cost = cost + shop[new_idx]; // 지금까지의 비용과 new_idx의 비용의 합
            sum_dis += bet_dis[new_idx-1]; // idx에서 출발해서 new_idx까지 가는 거리
            if(sum_dis > max_dis) break; // 거리를 넘어가면 종료
            if(cache[new_idx] > new_cost) { // new_idx 비용 합이 현재 계산한 비용 합보다 작으면 업데이트
                cache[new_idx] = new_cost;
                parent[new_idx] = idx;
                pq.push({-new_cost, new_idx});
            }
        }
    }

    cout << cache[n+1] << "\n"; // 도착지의 최소 비용

    // 부모를 타고 올라가면서 방문하는 정비소 저장
    stack<int> stk;
    int k = parent[n+1];
    int sz = 0;
    while(k != 0) {
        stk.push(k);
        k = parent[k];
        sz++;
    }

    cout << sz << "\n";
    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    return 0;
}