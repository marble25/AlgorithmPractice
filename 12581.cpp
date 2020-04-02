//
// Created by marble on 20. 4. 2..
//

// 간단하게 맞춘 문제
// bfs와 cnt 처리를 해주면 된다.

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
int arr[100001]; // x위치를 가는데 걸리는 최소 시간
int cnt[100001]; // x위치를 최소로 오는데 가능한 경우의 수
int min_time = INT32_MAX;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(arr, 0, sizeof(arr));

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    arr[n] = 0;
    cnt[n] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(arr[x] > min_time) { // 최소 시간보다 많이 걸린다면 break
            break;
        }

        if(x == k) { // k에 도달한다면 최소시간을 업데이트해주고 continue
            min_time = min(min_time, arr[x]);
            continue;
        }

        if(x-1 >= 0) {
            if(arr[x-1] == 0) {
                q.push(x-1);
                arr[x-1] = arr[x] + 1;
                cnt[x-1] = cnt[x]; // x에 도달할 수 있는 가짓수를 그대로 x-1에도 적용해줌
            } else if(arr[x-1] == arr[x] + 1) { // x-1에 도달하는 시간이 x에 도달한 시간 + 1이면 같은 시간으로 찾는 경우이므로 경우의 수를 더해줌
                cnt[x-1] += cnt[x];
            }
        }

        // 나머지도 마찬가지
        if(x+1 <= 100000) {
            if(arr[x+1] == 0) {
                q.push(x+1);
                arr[x+1] = arr[x] + 1;
                cnt[x+1] = cnt[x];
            } else if(arr[x+1] == arr[x] + 1) {
                cnt[x+1] += cnt[x];
            }
        }

        if(x*2 <= 100000) {
            if(arr[x*2] == 0) {
                q.push(x*2);
                arr[x*2] = arr[x] + 1;
                cnt[x*2] = cnt[x];
            } else if(arr[x*2] == arr[x] + 1) {
                cnt[x*2] += cnt[x];
            }

        }
    }
    cout << min_time << '\n' << cnt[k];

    return 0;
}