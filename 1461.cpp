//
// Created by marble on 20. 6. 20..
//

// 생각지도 못한 오류를 고쳤더니 쉽게 맞았던 문제
// 그리디를 이용해서 고민을 했더니 풀 수 있었다.

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

int n, m;
int arr[10005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n); // 크기 순서대로 정렬

    int p = 0;
    while(p < n) { // p부터는 0보다 큰 수, p-1까지는 0보다 작은 수
        if(arr[p] > 0) {
            break;
        }
        p++;
    }
    int dis = 0;
    int min_m_dis=987654321, min_p_dis=987654321; // minus 부분과 plus 부분의 최소값을 따로 저장하는 변수
    for(int k=0;k<m;k++) { // 시작점을 0~m-1로 설정
        int minus_dis = 0, plus_dis = 0;
        for(int i=p-1-k;i>0;i-=m) { // 시작점에서 m칸만큼씩 가면서 2 곱한 값 더해줌(왕복이므로)
            minus_dis += 2 * abs(arr[i]);
        }
        if(arr[0] < 0) { // 끝점도 0보다 작은 경우에 더해줌(끝점은 어떤 경우이든 무조건 방문)
            minus_dis += 2 * abs(arr[0]);
        }


        for(int i=p+k;i<n-1;i+=m) { // 시작점에서 m칸만큼씩 가면서 2 곱한 값 더해줌(왕복이므로)
            plus_dis += 2 * abs(arr[i]);
        }
        if(arr[n-1] > 0) { // 끝점도 0보다 큰 경우에 더해줌(끝점은 어떤 경우든 무조건 방문)
            plus_dis += 2 * abs(arr[n-1]);
        }

        // min값 교체
        min_m_dis = min(minus_dis, min_m_dis);
        min_p_dis = min(plus_dis, min_p_dis);
    }
    dis = min_m_dis + min_p_dis - max(abs(arr[0]), abs(arr[n-1])); // plus와 minus 값에서 가장 절대값이 큰 값을 빼줌(그 곳은 편도로 방문)
    cout << dis;

    return 0;
}