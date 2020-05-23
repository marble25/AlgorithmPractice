//
// Created by marble on 20. 5. 24..
//

// 메모리 제한이 굉장히 타이트해서 자세히 보았더니 우선순위 큐로 풀 수 있는 문제였다.

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

int n, x;
priority_queue<int> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> x;

            if(pq.size() >= n) { // 넘치는 상황이면
                int past = -pq.top(); // queue에서 가장 작은 값
                if(past < x) { // 가장 작은 값이 x보다 작으면 가장 작은 값 빼고 x 집어넣음
                    pq.pop();
                    pq.push(-x);
                }
            } else  { // x 넣음
                pq.push(-x);
            }
        }
    }

    cout << -pq.top();

    return 0;
}