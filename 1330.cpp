//
// Created by marble on 20. 6. 1..
//

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if(a > b) cout << ">";
    else if(a < b) cout << "<";
    else cout << "==";

    return 0;
}