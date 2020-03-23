#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    vector<int> v;

    cin >> n;
    v.push_back(INT32_MIN); // 가장 작은 값을 default로 넣어줌

    int cnt=0;
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        if (temp > v.back()) { // 벡터에 있는 가장 큰 값보다 크면
            v.push_back(temp); // 그냥 넣고
            cnt ++; // LIS 길이 + 1해줌
        } else {
            auto low = lower_bound(v.begin(), v.end(), temp);
            *low = temp; // temp보다 약간 큰 값을 temp로 바꿔줌
        }
    }
    cout << cnt;

    return 0;
}