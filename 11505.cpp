//
// Created by marble on 20. 12. 22..
//

// 세그먼트 트리 계속 공부중
// 더 빠르게 구현할 수 있도록 해야겠다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

#define MOD 1000000007
using namespace std;

int n, m, k;
int arr[1000000];
long long tree[2000000];

long long init(int node, int start, int end) {
    if(start == end) {
        return tree[node] = arr[start];
    }

    long long left = init(node*2, start, (start+end)/2);
    long long right = init(node*2+1, (start+end)/2+1, end);
    return tree[node] = left * right % MOD;
}

long long update(int node, int start, int end, int idx, long long value) {
    if(idx < start || end < idx) { // 변경이 없는 경우는 기존 값을 돌려줌
        return tree[node];
    }

    if(start == end) { // 끝까지 내려가는 경우는 idx값일 때 뿐이므로 값을 넣어주면 됨
        return tree[node] = value;
    }

    long long left = update(node*2, start, (start+end)/2, idx, value);
    long long right = update(node*2+1, (start+end)/2+1, end, idx, value);
    return tree[node] = left * right % MOD;

}

long long get(int node, int start, int end, int left, int right) {
    if(start > right || end < left) { // 범위가 아니면 1 리턴
        return 1;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    long long l = get(node*2, start, (start+end)/2, left, right);
    long long r = get(node*2+1, (start+end)/2+1, end, left, right);
    return l * r % MOD;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    init(1, 0, n-1);
    for(int i=0;i<m+k;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            update(1, 0, n-1, b-1, c);
        } else {
            cout << get(1, 0, n-1, b-1, c-1) << "\n"; // 범위 할 때 b-1, c-1해줘야 하는 것 명심!
        }
    }

    return 0;
}