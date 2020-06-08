//
// Created by marble on 20. 6. 9..
//

// 경우를 빠뜨리고 세지 말자.

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

    int a, b, c;
    cin >> a >> b >> c;
    if(a+b == c) {
        cout << a << '+' << b << '=' << c;
    } else if(a-b == c) {
        cout << a << '-' << b << '=' << c;
    } else if(a*b == c) {
        cout << a << '*' << b << '=' << c;
    } else if(a/b == c){
        cout << a << '/' << b << '=' << c;
    } else if(a == b+c) {
        cout << a << '=' << b << '+' << c;
    } else if(a == b-c) {
        cout << a << '=' << b << '-' << c;
    } else if(a == b*c) {
        cout << a << '=' << b << '*' << c;
    } else if(a == b/c) {
        cout << a << '=' << b << '/' << c;
    }

    return 0;
}