//
// Created by marble on 20. 6. 18..
//

// 굉장히 구현 조건이 귀찮은 문제
// 어려운 문제는 아니지만, 생각할 부분이 많았다...

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

int n;
int sum[3] = {0};
int ans[3] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int x;
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> x;
            sum[j] += x*x; // 제곱을 더해줌으로써 unique 하게 구별할 수 있도록 했다.
            ans[j] += x;
        }
    }

    int sel = 0, re = 0;
    if(sum[0] == sum[1] && sum[1] == sum[2]) {
        sel = 0;
        re = ans[0];
    } else if(sum[0] == sum[1] && sum[0] > sum[2]) {
        sel = 0;
        re = ans[0];
    } else if(sum[0] == sum[2] && sum[0] > sum[1]) {
        sel = 0;
        re = ans[0];
    } else if(sum[2] == sum[1] && sum[2] > sum[0]) {
        sel = 0;
        re = ans[2];
    } else {
        if(sum[0] < sum[1]) {
            sel = 2;
            re = ans[1];
        } else {
            sel = 1;
            re = ans[0];
        }

        if(sum[sel-1] < sum[2]) {
            sel = 3;
            re = ans[2];
        }
    }

    cout << sel << " " << re;

    return 0;
}