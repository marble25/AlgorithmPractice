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

int n, m;
int arr[10005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int start = 0, end = n-1;
    if(abs(arr[0]) < abs(arr[n-1])) {
        end -= n%m;
    } else {
        start += n%m;
    }

    int p = start;
    int dis = 0;
    while(p <= end && arr[p] < 0) {
        dis += abs(arr[p]) * 2;
        p += m;
    }

    p = end;
    while(p >= start && arr[p] > 0) {
        dis += abs(arr[p]) * 2;
        p -= m;
    }

    cout << dis;

    return 0;
}