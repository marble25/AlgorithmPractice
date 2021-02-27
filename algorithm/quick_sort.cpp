//
// Created by 이지호 on 21. 2. 28..
//

//
// Created by 이지호 on 21. 2. 28..
//

#include <cstdlib>
#include <cstdio>

#define SIZE 10

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for(int j=start;j<=end-1;j++) {
        if(arr[j] < pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[end]);
    return i+1;
}

void quickSort(int arr[], int start, int end) {
    if(start > end) {
        return;
    }
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);

}

void quickSort(int arr[]) {
    quickSort(arr, 0, SIZE-1);
}

void print(int arr[]) {
    for(int i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 1, 10, 2, 7, 9, 4, 6, 8};
    quickSort(arr);
    print(arr);
    return 0;
}