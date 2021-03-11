//
// Created by 이지호 on 21. 3. 11..
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

long long n;
long long arr[10] = {0};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    long long log_val = log10(n);
    for(long long i=log_val;i>=0;i--) {
        long long exp = pow(10, i);
        long long current_num = n / exp % 10;
        long long remainder = n % exp;

        for(int j=0;j<10;j++) {
            arr[j] += current_num * i * exp / 10;
            if(j == 0) {
                arr[j] -= exp;
            }

            if(current_num > j) {
                arr[j] += exp;
            } else if(current_num == j){
                arr[j] += remainder + 1;
            }
        }
    }

    for(int i=0;i<10;i++) {
        cout << arr[i] << " ";
    }
}