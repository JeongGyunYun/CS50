#include <stdio.h>
#include <math.h>
#define SIZE 5



int main(void) {
    int a = 12345;
    //TODO 숫자를 배열 형태로 변환

    return 0;
}

void swap(int *arr, int id1, int id2) {
    if (id1 == id2) return;
    arr[id1] ^= arr[id2];
    arr[id2] ^= arr[id1];
    arr[id1] ^= arr[id2];
}


/**
 *
 * @param arr   정렬되지 않은 배열
 * @param left  배얼의 첫 번째 index
 * @param right 배열의 두 번째 index
 */
void quick_sort(int *arr, int left, int right) {
    int toLeft, toRight, pivot;

    if(left < right) {
        pivot = arr[left];
        toRight = left;
        toLeft = right + 1;
        do {
            do toRight++; while (pivot > arr[toRight]);
            do toLeft--; while (pivot < arr[toLeft]);
            if (toRight < toLeft) swap(arr, toRight, toLeft);
        } while (toRight < toLeft);
        swap(arr, left, toLeft);
        quick_sort(arr, left, toLeft - 1);
        quick_sort(arr, toLeft + 1, right);
    }
}


