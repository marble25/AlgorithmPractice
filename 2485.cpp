//
// Created by 이지호 on 21. 2. 27..
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
int sum = 0;
int arr[100005];

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int n1 = arr[1]-arr[0];
    int n2 = arr[2]-arr[1];
    int g = gcd(max(n1, n2), min(n1, n2));
    for(int i=2;i<n-1;i++) {
        int m = arr[i+1]-arr[i];
        g = gcd(max(m, g), min(m, g));
    }

    for(int i=0;i<n-1;i++) {
        sum += (arr[i+1]-arr[i]) / g - 1;
    }
    cout << sum;
    return 0;
}