//
// Created by 이지호 on 21. 4. 8..
//

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, s, r;
    int ship[11] = {0};
    int temp[11] = {0};
    cin >> n >> s >> r;
    for(int i=1;i<=n;i++) ship[i] = 1;
    for(int i=0;i<s;i++) {
        int x;
        cin >> x;
        ship[x]--;
    }

    for(int i=0;i<r;i++) {
        int x;
        cin >> x;
        ship[x]++;
    }

    for(int i=1;i<=n;i++) {
        temp[i] = ship[i];
    }

    for(int i=1;i<=n;i++) {
        if(i+1 <= n && ship[i] == 2 && ship[i+1] == 0) {
            ship[i]--;
            ship[i+1]++;
        } else if(i-1 > 0 && ship[i] == 2 && ship[i-1] == 0) {
            ship[i]--;
            ship[i-1]++;
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        if(ship[i] == 0) cnt++;
    }
    int ans = cnt;

    for(int i=1;i<=n;i++) {
        ship[i] = temp[i];
    }

    for(int i=1;i<=n;i++) {
        if(i-1 > 0 && ship[i] == 2 && ship[i-1] == 0) {
            ship[i]--;
            ship[i-1]++;
        }else if(i+1 <= n && ship[i] == 2 && ship[i+1] == 0) {
            ship[i]--;
            ship[i+1]++;
        }
    }
    cnt = 0;
    for(int i=1;i<=n;i++) {
        if(ship[i] == 0) cnt++;
    }
    ans = min(ans, cnt);
    cout << ans;
}