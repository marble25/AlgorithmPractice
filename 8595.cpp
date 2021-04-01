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

char str[5000005];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin >> str;

    int num = -1;
    long long sum = 0;
    for(int i=0;i<n;i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            if(num == -1) num = str[i] - '0';
            else num = num * 10 + str[i] - '0';
        } else {
            if(num != -1) {
                sum += num;
                num = -1;
            }
        }
    }

    if(num != -1) {
        sum += num;
    }

    cout << sum;
}