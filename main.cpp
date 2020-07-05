// 간단한 문제

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

char s[105];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    int sz = strlen(s);

    int num = 0; // 처음 값을 설정
    if(sz % 3 == 1) {
        num = s[0] - '0';
    } else if(sz % 3 == 2) {
        num = (s[0] - '0') * 2 + (s[1] - '0');
    }

    if(num != 0) { // 처음 값이 있으면 출력
        cout << num;
    }

    for(int i=sz%3;i<sz;i+=3) { // 3개 단위로 끊어서 출력
        num = (s[i] - '0') * 4 + (s[i+1] - '0') * 2 + (s[i+2] - '0');
        cout << num;
    }

    return 0;
}