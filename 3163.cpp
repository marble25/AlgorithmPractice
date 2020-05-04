#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> ants[100005];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, l, k;
		cin >> n >> l >> k;
		vector<int> v;
		int x, c=0;
		for (int i = 0; i < n; i++) {
			cin >> x >> ants[i].second;
			if (ants[i].second < 0) {
				ants[c++].first = x;
			}
			else {
				v.push_back(l - x);
			}
		}
		for (int it : v) {
			ants[c++].first = it;
		}
		sort(ants, ants + n);
		cout << ants[k - 1].second << "\n";
		
	}
	
}