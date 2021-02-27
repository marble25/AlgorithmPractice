//
// Created by 이지호 on 21. 2. 28..
//

#include <cstdlib>
#include <cstdio>

#define SIZE 10

// 정렬된 집합과 아직 정렬 안된 집합으로 나누어 정렬안된 집합의 원소를 하나씩 빼서 정렬된 집합으로 넣어주는 정렬
void insertionSort(int arr[]) {
    int key, j;
    for(int i=1;i<SIZE;i++) {
        key = arr[i];
        j=i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

// 가장 작은 원소 찾기, 두 번째로 작은 원소 찾기 등등..
void selectionSort(int arr[]) {
    int temp;
    for(int i=0;i<SIZE-1;i++) {
        int min_idx = i;
        for(int j=i+1;j<SIZE;j++) {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// 양옆 원소를 비교해서 큰거랑 작은거랑 바꿔줌
void bubbleSort(int arr[]) {
    for(int i=0;i<SIZE-1;i++) {
        for(int j=0;j<SIZE-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[]) {
    for(int i=0;i<SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 1, 10, 2, 7, 9, 4, 6, 8};
    bubbleSort(arr);
    print(arr);
    return 0;
}