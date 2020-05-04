#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int num[100000], n;
long long func() {
	stack<long long> st;
	long long i, ret = 0;

	st.push(-1);
	for (i = 0; i < n; i++) {
		while (!st.empty() && num[i] < num[st.top()]) {
			int tmp = st.top();
			st.pop();
			if (!st.empty()) {
				ret = max(ret, (long long)(num[tmp] * (i - st.top() - 1)));
			}
		}
		st.push(i);
	}
	while (!st.empty()) {
		int tmp = st.top();
		st.pop();
		if (!st.empty()) {
			ret = max(ret, (long long)(num[tmp] * (i - st.top() - 1)));
		}
	}
	return ret;
}
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		printf("%lld\n", func());
	}
}