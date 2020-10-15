//
// Created by marble on 20. 10. 15..
//

// 오랜만에 비트마스킹과 백트래킹을 이용한 문제였다

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

int n, k;
string str;
int checked[50] = {0};

int ans = 0;

void f(int cur, int comb, int stage) {
    if(stage == k-5) { // antic를 제외한 마지막에 도달했을 때
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if((comb & checked[i]) >= checked[i]) { // check의 모든 문자열이 포함되어 있을 때
                cnt++;
            }
        }
        ans = max(cnt, ans);
        return;
    }
    for(int i=cur+1;i<26;i++) { // 다음 문자
        char c = i + 'a';
        if(c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
        f(i, (comb | (1 << i)), stage+1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int temp = 0;
        cin >> str;

        for(int j=0;j<str.size();j++) { // 5개를 빼고 시작
            if(str[j] == 'a' || str[j] == 'n' || str[j] == 't' || str[j] == 'i' || str[j] == 'c') continue;
            temp = (temp | (1 << (str[j] - 'a')));
        }
        checked[i] = temp;
    }

    if(k < 5) { // 5보다 작으면 무조건 안됨(기본 포함 문자 때문에)
        cout << 0;
        return 0;
    }

    f(0, 0, 0);
    cout << ans;
    return 0;
}