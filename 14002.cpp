//
// Created by marble on 20. 11. 16..
//

// 오랜만에 풀어본 DP 연습문제..
// 간단히 clear

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

int n;
int arr[1005];

int cache[1005] = {0};
int parent[1005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i] <= arr[j]) continue; // 증가하지 않으면 다른 숫자로
            if(cache[j] + 1 > cache[i]) { // 기존에 있는 값보다 더 크면(더 긴 수열 가능하면)
                cache[i] = cache[j] + 1; // 새로운 값 대입
                parent[i] = j; // 부모를 다른 수로 설정
            }
        }

        if(cache[i] == 0) { // 이보다 작은 값이 없을 경우 이 값이 시작
            cache[i] = 1;
            parent[i] = -1;
        }
    }
    int mx = 0;
    int mi = 0;
    for(int i=0;i<n;i++) {
        if(cache[i] > mx) { // 가장 큰 값을 찾아봄
            mx = cache[i];
            mi = i;
        }
    }
    stack<int> stk;
    while(true) { // 조상까지 찾아가면서 수열을 구성
        stk.push(arr[mi]);
        mi = parent[mi];

        if(mi == -1) break;
    }

    cout << mx << "\n";
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}