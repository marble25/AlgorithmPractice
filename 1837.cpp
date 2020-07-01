//
// Created by marble on 20. 7. 2..
//

// 요즘 실수가 다시 많아지는 것 같다.
// 제발 실수좀 줄이자..

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

char p[105] = {0};
int k;

bool check[1000005];
vector<int> pn;

bool is_divided(int x) { // p 배열이 x로 나누어지는지 판단하는 함수
    int ret = 0;

    int sz = strlen(p);
    for(int i=0;i<sz;i++) {
        ret = (ret * 10 + (p[i] - '0')) % x;
    }

    return (ret == 0); // 나머지가 0이면 나누어짐
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> p;
    cin >> k;

    for(int i=2;i<k;i++) { // k보다 작은 소수를 모두 추가
        if(!check[i]) {
            pn.push_back(i);
            for(int j=1;i*j<k;j++) {
                check[i*j] = true;
            }
        }
    }

    for(auto &it:pn) { // k보다 작은 소수로 나누어지면 BAD 출력
        if(is_divided(it)) {
            cout << "BAD " << it;
            return 0;
        }
    }

    cout << "GOOD";

    return 0;
}