//
// Created by marble on 20. 4. 26..
//

// 분할정복을 사용하면 간단히 맞출 수 있는 문제
// 예전에 풀어본 경험이 있어서 쉽게 맞추었던 것 같다.

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
long long arr[100005] = {0};

long long f(int low, int high) {
    if(low == high) return arr[low];
    int mid = (low + high) / 2;
    long long left = f(low, mid);
    long long right = f(mid+1, high);

    long long current_high = arr[mid];
    long long cross = 0;
    int l=mid, r=mid, i=1;
    while(l >= low && r <= high) {
        cross = max(cross, current_high * i);
        if(l-1 >= low && r+1 <= high && arr[l-1] < arr[r+1]) r++;
        else if(l-1 >= low && r+1 <= high && arr[l-1] >= arr[r+1]) l--;
        else if(l == low) r++;
        else if(r == high) l--;
        current_high = min(current_high, min(arr[l], arr[r]));
        i++;
    }
    return max(max(left, right), cross);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << f(0, n-1);


    return 0;
}