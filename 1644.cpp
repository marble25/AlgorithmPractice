//
// Created by marble on 20. 5. 1..
//

// 투 포인터를 이용한 간단한 문제

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n;
bool c[4000001];
vector<int> p;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    p.push_back(2);
    p.push_back(3);
    p.push_back(5);
    for(int i=7;i<=n;i+=2) {
        if(i % 3 == 0 || i % 5 == 0) continue; // 몇개에 대해서 더 pruning을 해주었다.
        if(c[i]) continue;
        p.push_back(i);
        for(int j=1;j*i<=n;j++) {
            c[j*i] = true;
        }
    }

    int s = p.size();
    int sum = 0;
    int cnt = 0;

    int f=0, r=-1;
    while(true) {
        if(sum <= n) { // sum이 n보다 작거나 같으면 큰 값을 더해봄
            r++;
            if(r >= s) break; // 범위보다 커지면 break
            sum += p[r];
        } else { // sum이 n보다 크면 작은 값을 하나 빼봄
            sum -= p[f];
            f++;
        }

        if(sum == n) { // 답과 같으면 정답
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}