#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int t;
	int n, m;
	int arr[100];
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		queue<pair<int, int>> qu;
		priority_queue<int> pq;
		int result = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			qu.push({ arr[j], j });
			pq.push(arr[j]);
		}
		
		while (qu.size()) {
			int here = qu.front().first;
			int num = qu.front().second;
			qu.pop();
			if (pq.top() == here) {
				result++;
				pq.pop();
				if (num == m)break;
			}
			else qu.push({ here,num });
		}


		cout << result << "\n";
	}
}