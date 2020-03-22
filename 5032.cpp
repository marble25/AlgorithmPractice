//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int e, f, c;
    cin >> e >> f >> c;
    e += f;

    int result = 0;
    while(e >= c) {
        result += e / c;
        e = e / c + e % c;
    }
    cout << result << endl;
    return 0;
}