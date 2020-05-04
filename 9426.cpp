#include <iostream>
#include <algorithm>
#define MAX_N 250001
#define MAX 65536
using namespace std;
long long seg[4 * MAX], a[MAX_N], n, k, res=0;
long long update(long long pos, long long val, long long node, long long left, long long right) {
	if (right < pos || pos < left) {
		return seg[node];
	}
	if (left == right) {
		seg[node] += val;
		return seg[node];
	}
	long long mid = (left + right) / 2;
	seg[node] = update(pos, val, node * 2, left, mid) + update(pos, val, node * 2 + 1, mid + 1, right);
	return seg[node];
}
long long query(long long val, long long node, long long left, long long right) {
	long long mid = (left + right) / 2;
	if (left == right) {
		return left;
	}
	if (seg[node * 2] >= val) {
		return query(val, node * 2, left, mid);
	}
	return query(val - seg[node * 2], node * 2 + 1, mid + 1, right);
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k - 1; i++) {
		update(a[i], 1, 1, 0, MAX - 1);

	}
	for (int i = k - 1; i < n; i++) {
		update(a[i], 1, 1, 0, MAX - 1);
		res += query((k + 1) / 2, 1, 0, MAX - 1);
		update(a[i - k + 1], -1, 1, 0, MAX - 1);

	}
	cout << res;
}