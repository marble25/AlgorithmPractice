//
// Created by marble on 20. 9. 14..
//

// 조금만 생각하면 쉽게 맞출 수 있는 문제
// 순환하는 사이클의 단위를 구해서 그 단위수의 최소공배수를 찾으면 되는 문제

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

int n;
int arr[20005];
int visited[20005] = {0};

long long re = 1;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++) {
        if(visited[i] == 0) { // 방문 안했다면
            int x = arr[i];
            long long cnt = 1;
            while(x != i) { // 사이클이 나올 때까지 cnt 더해줌
                visited[x] = 1;
                cnt++;
                x = arr[x];
            }
            re = re * cnt / gcd(max(re, cnt), min(re, cnt)); // 기존 값과 새로운 값의 최소공배수 찾음
        }
    }
    cout << re;

    return 0;
}