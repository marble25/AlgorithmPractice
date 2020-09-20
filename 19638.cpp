//
// Created by marble on 20. 9. 20..
//

// priority_queue를 이용해서 전략대로 그대로 수행하면 쉽게 풀리는 문제

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

int n, h, t;
priority_queue<int> giant;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> h >> t;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        giant.push(x);
    }

    for(int i=0;i<t;i++) {
        int top = giant.top();
        giant.pop();

        if(top < h) { // 중간에 더 작은 값이 나왔다면 출력 후 종료
            cout << "YES\n";
            cout << i;
            return 0;
        }

        top = ( top == 1? 1: top/2); // 1이면 그대로 1이고, 아니면 반으로 나눔
        giant.push(top); // 거인들을 다시 넣음
    }

    int top = giant.top();
    if(top < h) { // 가장 큰 거인보다 센티가 더 크다면 t번만에 성공
        cout << "YES\n";
        cout << t;
    } else {
        cout << "NO\n";
        cout << top;
    }
}