//
// Created by 이지호 on 21. 3. 2..
//

#include <cstdio>

int max_exp(int arr[], int n) {
    int mx = arr[0];
    for(int i=1;i<n;i++) {
        if(mx < arr[i]) mx = arr[i];
    }

    int exp = 0;
    while(mx > 0) {
        mx /= 10;
        exp++;
    }
    return exp;
}

void count_sort(int arr[], int n, int exp) {
    int temp[n];
    int count[10] = {0};

    for(int i=0;i<n;i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for(int i=1;i<10;i++) {
        count[i] += count[i-1];
    }

    for(int i=n-1;i>=0;i--) {
        temp[count[(arr[i] / exp) % 10]-1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i=0;i<n;i++) {
        arr[i] = temp[i];
    }

}

void radix_sort(int arr[], int n) {
    int mx_exp = max_exp(arr, n);
    int exp = 1;
    for(int i=0;i<mx_exp;i++) {
        count_sort(arr, n, exp);
        exp *= 10;
    }
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radix_sort(arr, n);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
}