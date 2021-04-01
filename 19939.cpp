//
// Created by 이지호 on 21. 4. 1..
//

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
int arr[1000] = {0};
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int sum = 0;

    for(int i=0;i<k;i++) {
        arr[i] = i + 1;
        sum += i+1;
        if(sum > n) {
            cout << -1;
            return 0;
        }
    }

    int idx = k-1;
    while(sum < n) {
        arr[idx--]++;
        sum++;
        if(idx < 0) idx = k-1;
    }

    cout << arr[k-1] - arr[0];


    return 0;
}