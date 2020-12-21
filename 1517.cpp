//
// Created by marble on 20. 12. 21..
//

// 확실하게 이해는 안되는 문제
// 곰곰히 생각을 많이 해 봐야겠다.

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

int n;
int arr[500005];
int tmp[500005];

long long ans = 0;

void mergeArr(int p, int q, int r) {
    int idx = p;
    int i = p, j = q+1;
    long long cnt = 0;

    while(i <= q || j <= r) {
        if(i > q) { // 앞에 것을 다 복사했으면
            tmp[idx++] = arr[j++];
            cnt++; // 겹칠 선 개수 증가
        } else if(j > r) { // 뒤에 것을 다 복사했으면
            tmp[idx++] = arr[i++];
            ans += cnt; // 선 개수만큼 겹침
        } else if(arr[i] <= arr[j]) { // 앞에 것이 뒤에 것보다 작으면
            tmp[idx++] = arr[i++];
            ans += cnt; // 선 개수만큼 겹침
        } else { // 앞에 것이 뒤에 것보다 크면
            tmp[idx++] = arr[j++];
            cnt++; // 겹칠 선 개수 증가
        }
    }
    for(i=p;i<=r;i++) {
        arr[i] = tmp[i];
    }
}

void mergeSort(int p, int r) {
    int q;
    if(p < r) {
        q = (p + r) / 2;
        mergeSort(p, q);
        mergeSort(q+1, r);
        mergeArr(p, q, r);

    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    mergeSort(0, n-1);
    cout << ans;

    return 0;
}