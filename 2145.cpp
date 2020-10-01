//
// Created by marble on 20. 10. 1..
//

// 굉장히 간단한 연습 문제

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

char s[10];

int calc(int x) {
    int re = 0;
    while(x != 0) {
        re += (x % 10);
        x /= 10;
    }

    return re;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        cin >> s;

        int number = 0;
        for(int i=0;i<strlen(s);i++) {
            number = number * 10 + (s[i] - '0');
        }

        if(number == 0) break;
        while(number >= 10) {
            number = calc(number);
        }

        cout << number << "\n";
    }

    return 0;
}