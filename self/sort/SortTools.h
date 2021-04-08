#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <assert.h>

/**
 * @brief 交换数组两个下标值
 * @param arr 
 * @param i
 * @param j
 *
 * @return
 */
void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * @brief 生成随机数组
 * @param arr 传入空数组
 * @param max 生成数组的长度
 * @param rangeL 最小值
 * @param rangeR 最大值
 *
 * @return
 */
void GetRandOrderArray(int arr[], int max, int rangeL, int rangeR) {
    srand(time(NULL));
    for (int i = 0; i < max; ++i) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
}

/**
 * @brief 拷贝已有的数组
 * @param arr 传入空数组
 * @param max 生成数组的长度
 * @param swapTimes 交换次数
 *
 * @return
 */
void CopyArray(int copyArr[], int sourceArr[], int max) {
    memcpy(copyArr, sourceArr, sizeof(int) * max);
}

/**
 * @brief 生成近乎有序数组
 * @param arr 传入空数组
 * @param max 生成数组的长度
 * @param swapTimes 交换次数
 *
 * @return
 */
void GetNearlyOrderArray(int arr[], int max, int swapTimes) {
    for (int i = 0; i < max; ++i) {
        arr[i] = i;
    }

    srand(time(NULL));

    for (int i = 0; i < swapTimes; ++i) {
        int pos_x = rand() % max;
        int pos_y = rand() % max;
        Swap(arr, pos_x, pos_y);
    }
}

/**
 * @brief 输出数组(如果数组长度大于100则不输出)
 * @param arr 数组
 * @param max 数组的长度
 *
 * @return
 */
void PrintArray(int arr[], int max) {
    if (max > 100) {
        return;
    }
    for (int i = 0; i < max; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 判断数组是否有序
 * @param arr 数组
 * @param max 数组的长度
 *
 * @return 1-有序, 0-无序
 */
int IsSort(int arr[], int max) {
    for (int i = 0; i < max - 1; ++i) {
        if (arr[i] > arr[i+1]) {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief 判断两个数组是否相同
 * @param arr1 数组
 * @param arr2 数组
 * @param max 数组的长度
 *
 * @return 1-有序, 0-无序
 */
int IsSame(int arr1[], int arr2[], int max) {
    for (int i = 0; i < max - 1; ++i) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief 排序模板
 * @param name 排序算法名称
 * @param sort 函数指针
 * @param arr 数组
 * @param max 数组的长度
 * @param standArr 正确顺序的数组
 *
 * @return
 */
void SortTemplate(char name[], void(*sort)(int arr[], int max), int arr[], int max, int standArr[]) {
    double start, end;
    start = clock();

    sort(arr, max);

    end = clock();

    PrintArray(arr, max);

    assert(IsSort(arr, max));
    assert(IsSame(arr, standArr, max));

    printf("array.size = %d, %s's time = %lf\n", max, name, (end - start) / 1000);
}
