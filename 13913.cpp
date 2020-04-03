//
// Created by marble on 20. 4. 3..
//

// 앞의 숨바꼭질 문제에 경로만 추가해주면 되는 문제

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

int n, k;
int arr[100001] = {0}; // x위치를 가는데 걸리는 최소 시간
int parent[100001] = {0}; // x위치의 이전 위치 저장
stack<int> route;
int min_time = INT32_MAX;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    arr[n] = 1;
    parent[n] = -1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == k) { // k에 도달한다면 최소시간 출력후 경로 출력
            cout << arr[x]-1 << '\n';
            int cur = x;
            while(cur != -1) { // 처음 노드가 아니면 계속 경로를 타고 올라감
                route.push(cur);
                cur = parent[cur];
            }

            while(!route.empty()) { // 경로 출력
                cout << route.top() << ' ';
                route.pop();
            }

            return 0;
        }

        if(x-1 >= 0 && arr[x-1] == 0) {
            q.push(x-1);
            arr[x-1] = arr[x] + 1;
            parent[x-1] = x;
        }

        if(x+1 <= 100000 && arr[x+1] == 0) {
            q.push(x+1);
            arr[x+1] = arr[x] + 1;
            parent[x+1] = x;
        }

        if(x*2 <= 100000 && arr[x*2] == 0) {
            q.push(x*2);
            arr[x*2] = arr[x] + 1;
            parent[x*2] = x;
        }

    }
    return 0;
}