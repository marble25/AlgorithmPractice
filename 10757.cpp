//
// Created by marble on 20. 4. 4..
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

char a[10005], b[10005];
char re[10005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a;
    cin >> b;

    int i = strlen(a)-1;
    int j = strlen(b)-1;

    int carry = 0;

    while(true) {
        if(i == -1 || j == -1) break;

        int x = a[i] - '0';
        int y = b[j] - '0';

        int sum = x+y+carry;
        carry = sum/10;

        re[max(i, j)] = (sum%10 + '0');
        i--;j--;
    }

    if(i == -1 && j != -1) {
        for(;j>=0;j--) {
            int sum = carry + (b[j] - '0');
            re[j] = (sum%10 + '0');
            carry = sum/10;
        }
    } else if(i != -1 && j == -1) {
        for(;i>=0;i--) {
            int sum = carry + (a[i] - '0');
            re[i] = (sum%10 + '0');
            carry = sum/10;
        }
    }

    if(carry == 1) cout << '1';
    cout << re;

    return 0;
}