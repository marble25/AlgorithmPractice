//
// Created by marble on 20. 3. 31..
//

// upper bound와 lower bound에 대해서 배울 수 있었던 문제
// 문제 접근이 쉽지만은 않았다.

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
int arr[500000];
int sorted_arr[500000];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }

    int ans = 1;
    sort(sorted_arr, sorted_arr+n);

    for(int i=0;i<n;i++) {
        // 현재 arr[i] 값을 sorted_arr에서 찾아봄
        // (upper_bound로 arr[i]보다 커지는 경계선을 찾았기 때문에 -1을 해서 arr[i]의 index를 가져옴
        // arr[i]가 자기 위치로 찾아가는데 뒤에 있다면 1번이면 되지만 앞에 있다면 index의 차만큼 swap을 해 줘야 한다.
        // swap의 최대는 앞으로 가야 하는 arr[i]와의 index 차이이다.
        int index = upper_bound(sorted_arr, sorted_arr+n, arr[i]) - sorted_arr - 1;
        if(index < i) { // arr[i]가 정렬된 배열에서 더 앞에 있을 때에 update
            ans = max(ans, i - index + 1);
        }
    }
    cout << ans;

    return 0;
}