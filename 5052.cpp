//
// Created by marble on 20. 6. 26..
//

// 다른 사람들이 많이 틀려서 어려운 문제인줄 알고 내가 구현한 것이 맞나 생각해 보았는데 의외로 한번에 맞추었다.
// 단순히 정렬 후 비교만 적절히 해주면(위, 아래로만 비교하면 됨) 쉽게 풀리는 문제

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

int t;
int n;
string l[10000];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> l[i];
        }
        sort(l, l+n); // 정렬

        bool flag = false;
        for(int i=1;i<n;i++) {
            int s1 = l[i-1].size(), s2 = l[i].size();
            if(l[i-1].compare(0, min(s1, s2), l[i], 0, min(s1, s2)) == 0) { // prefix가 공통되는 부분이 있으면 NO 출력
                flag = true;
                cout << "NO\n";
                break;
            }
        }

        if(!flag) { // prefix가 공통되는 부분 없으면 YES 출력
            cout << "YES\n";
        }
    }

    return 0;
}