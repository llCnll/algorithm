#include <stdio.h>

#include "SortTools.h"

#define MAX 100000

void SelectSort(int arr[], int max);
void InsertSort(int arr[], int max);
void InsertSort02(int arr[], int max);
void BubbleSort(int arr[], int max);
void BubbleSort02(int arr[], int max);

int main() {

    int arr01[MAX];
    int arr02[MAX];
    int arr03[MAX];
    int arr04[MAX];
    int arr05[MAX];

    //GetRandOrderArray(arr01, MAX, 0, MAX);
    GetNearlyOrderArray(arr01, MAX, MAX/100);
    CopyArray(arr02, arr01, MAX);
    CopyArray(arr03, arr01, MAX);
    CopyArray(arr04, arr01, MAX);
    CopyArray(arr05, arr01, MAX);


    SortTemplate((char*)"选择排序", SelectSort, arr01, MAX, arr01);
    SortTemplate((char*)"简单插入排序", InsertSort, arr02, MAX, arr01);
    SortTemplate((char*)"优化插入排序", InsertSort02, arr03, MAX, arr01);
    SortTemplate((char*)"简单冒泡排序", BubbleSort, arr04, MAX, arr01);
    SortTemplate((char*)"优化插入排序", BubbleSort02, arr05, MAX, arr01);

    return 0;
}

/**
 * @brief 优化冒泡排序
 *        (若此次冒泡无比较则提前结束)
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void BubbleSort02(int arr[], int max) {
    int flag = 1;
    for (int i = max-1; i > 0 && flag; i--) {
        flag = 0;
        for (int j = 0; j < i ; j++) {
            if (arr[j] > arr[j+1]) {
                Swap(arr, j, j+1);
                flag = 1;
            }
        }
    }
}

/**
 * @brief 简单冒泡排序
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void BubbleSort(int arr[], int max) {
    for (int i = max-1; i > 0; i--) {
        for (int j = 0; j < i ; j++) {
            if (arr[j] > arr[j+1]) {
                Swap(arr, j, j+1);
            }
        }
    }
}

/**
 * @brief 优化插入排序
 *        减少交换次数
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void InsertSort02(int arr[], int max) {
    for (int i = 0; i < max-1; ++i) {
        int j = i+1;
        int temp = arr[j];
        for (; j > 0 && arr[j-1] > temp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

/**
 * @brief 简单插入排序
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void InsertSort(int arr[], int max) {
    for (int i = 0; i < max-1; ++i) {
        for (int j = i+1; j > 0 && arr[j-1] > arr[j]; j--) {
            Swap(arr, j, j-1);
        }
    }
}

/**
 * @brief 选择排序
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void SelectSort(int arr[], int max) {
    for (int i = 0; i < max-1; ++i) {
        int tempIndex = i;
        for (int j = i+1; j < max; ++j) {
            if (arr[j] < arr[tempIndex]) {
                tempIndex = j;
            }
        }
        Swap(arr, i, tempIndex);
    }
}
