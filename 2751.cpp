#include <iostream>
using namespace std;

int arr[1000001];
int temp_arr[1000001];
void merge(int a[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (a[i] < a[j]) {
			temp_arr[k] = a[i];
			i++;
		}
		else {
			temp_arr[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			temp_arr[k++] = a[l];
		}
	}
	else if (j > right) {
		for (int l = i; l <= mid; l++) {
			temp_arr[k++] = a[l];
		}
	}
	for (int l = left; l <= right; l++) {
		a[l] = temp_arr[l];
	}
}
void merge_sort(int a[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

int main() {
	int n;
	int temp;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}