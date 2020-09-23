//
// Created by marble on 20. 9. 23..
//

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
int arr[100005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int ans = 1;
    int temp1 = 1, temp2 = 1;

    for(int i=0;i<n-1;i++) {
        if(arr[i] < arr[i+1]) {
            temp1 += 1;
            temp2 = 1;
        } else if(arr[i] > arr[i+1]) {
            temp2 += 1;
            temp1 = 1;
        } else {
            temp1 += 1;
            temp2 += 1;
        }
        ans = max(ans, max(temp1, temp2));
    }

    cout << ans;

    return 0;
}