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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int cnt = 0;
    int cache[1005] = {0};
    int start = 0, end = 1;

    cache[1] = 0;
    cache[2] = 1;
    for(int i=3;i<=n;i++) {
        if(i%2 == 1) {
            cache[i] = cache[i-1] * 2 - 1;
        } else {
            cache[i] = cache[i-1] * 2 + 1;
        }

    }

    return 0;
}