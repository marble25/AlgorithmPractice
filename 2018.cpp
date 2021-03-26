//
// Created by 이지호 on 21. 3. 26..
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
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n;
    int start=1, end=1;
    int cnt = 0;
    cin >> n;
    while(start <= end) {
        int sum = (start + end) * (end - start + 1) / 2;
        if(sum == n) {
            cnt++;
            start++;
        } else if(sum > n) {
            start++;
        } else {
            end++;
        }
    }

    cout << cnt;
}