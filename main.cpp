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

int n, w;
int candy1[250000], candy2[250000];
long long sum1[250005] = {0}, sum2[250005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> w;

    int c1 = 0, c2 = 0;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        if(x == 3) candy1[c1++] = y;
        else candy2[c2++] = y;
    }

    sort(candy1, candy1+c1);
    sort(candy2, candy2+c2);

    for(int i=c1-1;i>=0;i--) {
        sum1[c1-i] = sum1[c1-i-1] + candy1[i];
    }

    for(int i=c2-1;i>=0;i--) {
        sum2[c2-i] = sum2[c2-i-1] + candy2[i];
    }

    long long ans = 0;
    for(int i=0;i<=w/3;i++) {
        int j = (w-i) / 5;
        ans = max(ans, sum1[i] + sum2[j]);
    }


    return 0;
}