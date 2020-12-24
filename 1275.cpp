//
// Created by marble on 20. 12. 24..
//

// if문 서순...
// 세그먼트 트리 완전 정복을 위해 노력해야겠다.

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

int n, q;
long long arr[100005];
long long tree[400005];

long long init(int node, int start, int end) {
    if(start == end) {
        return tree[node] = arr[start];
    }

    long long l = init(node*2, start, (start+end)/2);
    long long r = init(node*2+1, (start+end)/2+1, end);

    return tree[node] = l + r;
}

long long update(int node, int start, int end, int idx, long long value) {
    if(idx < start || idx > end) { // 아랫 것과 바뀌면 바로 틀림 ..
        return tree[node];
    }

    if(start == end) {
        return tree[node] = value;
    }

    long long l = update(node*2, start, (start+end)/2, idx, value);
    long long r = update(node*2+1, (start+end)/2+1, end, idx, value);

    return tree[node] = l + r;
}

long long get(int node, int start, int end, int left, int right) {
    if(end < left || right < start) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    long long l = get(node*2, start, (start+end)/2, left, right);
    long long r = get(node*2+1, (start+end)/2+1, end, left, right);

    return l + r;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long x, y, a, b;

    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    init(1, 0, n-1);

    for(int i=0;i<q;i++) {
        cin >> x >> y >> a >> b;

        if(x > y) {
            long long temp = x;
            x = y;
            y = temp;
        }

        cout << get(1, 0, n-1, x-1, y-1) << "\n";
        update(1, 0, n-1, a-1, b);
    }

    return 0;
}