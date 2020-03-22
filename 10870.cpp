//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int fibonacci(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    return fibonacci(x-1) + fibonacci(x-2);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}