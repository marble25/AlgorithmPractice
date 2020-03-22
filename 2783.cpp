//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    double min_val = (double)x / (double)y;

    int n;
    cin >> n;
    while(n--) {
        cin >> x >> y;
        min_val = min(min_val, (double)x / (double)y);
    }

    cout << min_val * 1000 << endl;


    return 0;
}