#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SWAP(x, y, z) (z)=(x), (x)=(y), (y)=(z)
void prtArr(int *wInfo, int *hInfo, int w);
void buble_sort(int *lenArr,int *indexArr ,int cnt);


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
    int* wInfo = (int *)malloc(sizeof (*wInfo) * w);
    int* posTable = (int *)calloc(w, sizeof(*posTable));

    for(int i = 0; i < w; i++){
        fscanf(f, "%d", &hInfo[i]);
        wInfo[i] = i;
    }

    buble_sort(hInfo, wInfo, w);
    prtArr(wInfo, hInfo, w);
    puts("");

    int maxCntIndex = 0;
    for(int i = w-1; hInfo[i]>=hInfo[w-1]; i--, maxCntIndex++); //Max값을 갖는 원소 중 가장 작은 index값을 구함;
    printf("%d\n", w - maxCntIndex);
    int minIndex = w - maxCntIndex;
    printf("%d\n", w-maxCntIndex-wInfo[minIndex]);

    free(hInfo);
    free(wInfo);
    free(posTable);
    fclose(f);
    return 0;
}


void buble_sort(int *lenArr,int *indexArr ,int cnt){
    int temp = 0;
    for(int i = cnt; i >=0; i--){
        for(int j = 1; j<i; j++){
            if(lenArr[j]<lenArr[j-1]){
                SWAP(lenArr[j], lenArr[j-1], temp);
                SWAP(indexArr[j], indexArr[j-1], temp);
            }
        }
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