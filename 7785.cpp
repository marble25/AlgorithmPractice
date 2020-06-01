//
// Created by marble on 20. 6. 2..
//

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
map<string, int> mp;
map<int, string> mp_rev;
int status[1000005] = {0};
vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt = 1;
    string name, op;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> name >> op;
        if(mp[name] == 0) { // 기존에 없으면 추가
            mp_rev[cnt] = name;
            mp[name] = cnt++;
        }

        if(op == "enter") { // enter이면 status에 1로 설정
            status[mp[name]] = 1;
        } else { // leave면 status 0으로 설정
            status[mp[name]] = 0;
        }
    }

    for(int i=1;i<=n;i++) {
        if(status[i] == 1) { // status가 enter로 설정되어 있으면 v에 push
            v.push_back(mp_rev[i]);
        }
    }

    sort(v.begin(), v.end(), greater<>()); // v 정렬

    for(auto &it:v) {
        cout << it << "\n";
    }
    return 0;
}