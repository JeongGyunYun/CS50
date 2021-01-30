#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *arr, int id1, int id2);

void sort(int *wInfo, int *hInfo, int left, int right);

void prtArr(int *wInfo, int *hInfo, int w);

int main() {
    char filePath[100];
    printf("Input the file path >>\n");
    //scanf("%s", filePath);
    stpcpy(filePath, "../input.txt");

    FILE *f = fopen(filePath, "r");

    int w, h;
    fscanf(f, "%d", &w);
    fscanf(f, "%d", &h);

    int* hInfo = (int *)malloc(sizeof (*hInfo) * w);
    int* wInfo = (int *)malloc(sizeof (*hInfo) * w);

    for(int i = 0; i < w; i++){
        fscanf(f, "%d", &hInfo[i]);
        wInfo[i] = i;
    }

    sort(wInfo, hInfo, 0, w - 1);
    prtArr(wInfo, hInfo, w);

    //TODO hInfo배열에서 가장 큰 값만 찾아 index 저장
    //TODO index에 해당하는 wInfo배열 값을 새로운 배열에 저장, arr[0] = width


    free(hInfo);
    free(wInfo);
    fclose(f);
    return 0;
}

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

void prtArr(int *wInfo, int *hInfo, int w) {
    for(int i = 0; i<w ; i++){
        printf("%3d", hInfo[i]);
    }
    puts("");

    for(int i = 0; i<w ; i++){
        printf("%3d", wInfo[i]);
    }
}
