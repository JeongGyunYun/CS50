//
// Created by JeongGyun Yun on 2021/02/01.
//
#ifndef MISSION4_SORT_H
#define MISSION4_SORT_H

#endif//MISSION4_SORT_H


void swap(int *arr, int id1, int id2) {
    if (id1 == id2) return;
    arr[id1] ^= arr[id2];
    arr[id2] ^= arr[id1];
    arr[id1] ^= arr[id2];
}

void sort(int *wInfo, int *hInfo, int left, int right) {
    int toLeft, toRight, pivot;

    if(left < right) {
        pivot = hInfo[left];
        toRight = left;
        toLeft = right + 1;
        do {
            do toRight++; while (pivot > hInfo[toRight]);
            do toLeft--; while (pivot < hInfo[toLeft]);
            if (toRight < toLeft) {
                swap(hInfo, toRight, toLeft);
                swap(wInfo, toRight, toLeft);
            }
        } while (toRight < toLeft);
        swap(hInfo, left, toLeft);
        swap(wInfo, left, toLeft);
        sort(wInfo, hInfo, left, toLeft - 1);
        sort(wInfo, hInfo, toLeft + 1, right);
    }
}
