//
// Created by marble on 20. 4. 3..
//

// 순서를 잘못 쓴 줄 알았는데 알고보니 새로운 알고리즘을 적용해야 하는 문제다.
// 0-1 BFS는 deque를 사용, 같은 레벨은 앞에 넣고 다른 레벨은 뒤에 넣어주는 문제이다.

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(arr, 0, sizeof(arr));

    cin >> n >> k;

    deque<int> q;
    q.push_back(n);
    arr[n] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop_front();

        if(x == k) { // k에 도달한다면 최소시간을 업데이트해주고 continue
            cout << arr[x];
            return 0;
        }

        if(x != 0) {
            for(int i=2;i*x<=100000;i*=2) {
                if(x*i == k) {
                    cout << arr[x];
                    return 0;
                }

                if(arr[x*i] == 0) { // 방문 안한 노드라면 q 앞에 넣는다.(비용이 0이기 때문)
                    arr[x*i] = arr[x];
                    q.push_front(x*i);
                } else if(arr[x*i] > arr[x]) {
                    arr[x*i] = arr[x];
                }
            }
        }

        if(x-1 >= 0 && arr[x-1] == 0) { // q 뒤에 넣는다. (비용이 1이기 때문)
            q.push_back(x-1);
            arr[x-1] = arr[x] + 1;
        }

        if(x+1 <= 100000 && arr[x+1] == 0) { // q 뒤에 넣는다. (비용이 1이기 때문)
            q.push_back(x+1);
            arr[x+1] = arr[x] + 1;
        }

    }
    return 0;
}