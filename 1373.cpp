//
// Created by 이지호 on 21. 3. 3..
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

char s[1000005];
char re[400000];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    int sz = strlen(s);
    int k = 0;

    if(sz % 3 == 1) {
        re[k++] = s[0];
    } else if(sz % 3 == 2){
        re[k++] = (s[0] - '0') * 2 + s[1];
    }

    for(int i=sz%3;i<sz;i+=3) {
        re[k++] = (s[i] - '0') * 4 + (s[i+1] - '0') * 2 + s[i+2];
    }
    re[k] = 0;
    cout << re;

}