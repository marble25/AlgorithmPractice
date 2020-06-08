//
// Created by marble on 20. 6. 8..
//

// 굉장히 쉬운 문제였지만, 함정이 하나 있었던 문제
// 함정에 걸리지 않도록 꼼꼼히 봐야겠다.

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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    char s[55];

    cin >> n;
    cin >> s;

    int s_count = 0, l_count = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'S') s_count++;
        else l_count++;
    }

    cout << min(s_count + (l_count/2) + 1, n);
    return 0;
}