//
// Created by 이지호 on 21. 3. 5..
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

int rh, rv, sh, sv;
int n;

int rhi, rvi, shi, svi, pi;
int p = 987654321;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> rh >> rv >> sh >> sv;
    cin >> n;

    int mx1, mx2, p1, p2;

    for(int i=0;i<n;i++) {
        cin >> rhi >> rvi >> shi >> svi >> pi;

        mx1 = max((sh + (shi - 1)) / shi, (rh + (rhi - 1)) / rhi);
        mx2 = max((sv + (svi - 1)) / svi, (rv + (rvi - 1)) / rvi);
        p1 = mx1 * mx2 * pi;

        mx1 = max((sh + (svi - 1)) / svi, (rh + (rvi - 1)) / rvi);
        mx2 = max((sv + (shi - 1)) / shi, (rv + (rhi - 1)) / rhi);
        p2 = mx1 * mx2 * pi;
        p = min(p, min(p1, p2));
    }

    cout << p;
}