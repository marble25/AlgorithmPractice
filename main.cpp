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

int x, y, d, t;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x >> y >> d >> t;

    double dis = sqrt(x * x + y * y);
    int jump = dis / d;
    double spare = dis - jump * d;
    double result = dis;
    result = min(result, spare + jump * t);
    if(jump > 0) {
        result = min(result, (jump+1)*t*1.0);
    } else {
        result = min(result, d-spare+t);
        if(dis<d) result = min(result, t*2.0);
    }
    cout << fixed;
    cout.precision(20);
    cout << result;



    return 0;
}