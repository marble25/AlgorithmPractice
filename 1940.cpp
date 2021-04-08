//
// Created by 이지호 on 21. 4. 8..
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

int n, m;
int arr[100005] = {0};
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        arr[x]++;
    }

    int ans = 0;
    for(int i=1;i<=100000;i++) {
        if(m-i <= 100000 && m-i > 0 && arr[i] > 0 && arr[m-i] > 0 && i != m-i) {
            int count = min(arr[i], arr[m-i]);
            ans += count;
            arr[i] -= count;
            arr[m-i] -= count;
        }
    }

    cout << ans;
}