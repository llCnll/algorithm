#include <stdio.h>

#include "SortTools.h"

#define MAX 10000000

int __QsortComp(const void* a,const void* b);
void Qsort(int arr[], int max);

void SelectSort(int arr[], int max);
void InsertSort(int arr[], int max);
void InsertSort02(int arr[], int max);
void BubbleSort(int arr[], int max);
void BubbleSort02(int arr[], int max);

void QuickSort(int arr[], int max);
void __QuickSort(int arr[], int left, int right);
int __Partition(int arr[], int left, int right);

void MergeSort(int arr[], int max);
void __MergeSort(int arr[], int left, int right);
void __Merge(int arr[], int left, int mid, int right);

void HeapSortStack(int arr[], int max);
void __InitHeapStack(int arr[], int start_index, int max);
void __BuildHeapStack(int arr[], int start_index, int max);
void __HeapSortStack(int arr[], int max);

void HeapSortLoop(int arr[], int max);
void __BuildHeapLoop(int arr[], int start_index, int max);
void __HeapSortLoop(int arr[], int max);

int merge_temp_arr[MAX];

int arr00[MAX], arr01[MAX], arr02[MAX], arr03[MAX], arr04[MAX], arr05[MAX], arr06[MAX], arr07[MAX], arr08[MAX], arr09[MAX];

int main() {

    //GetRandOrderArray(arr01, MAX, 0, MAX);
    GetNearlyOrderArray(arr01, MAX, 1e3);
    CopyArray(arr00, arr01, MAX);
    CopyArray(arr02, arr01, MAX);
    CopyArray(arr03, arr01, MAX);
    CopyArray(arr04, arr01, MAX);
    CopyArray(arr05, arr01, MAX);
    CopyArray(arr06, arr01, MAX);
    CopyArray(arr07, arr01, MAX);
    CopyArray(arr08, arr01, MAX);
    CopyArray(arr09, arr01, MAX);

    SortTemplate((char*)"qsort排序", Qsort, arr00, MAX, arr00);

    //SortTemplate((char*)"选择排序", SelectSort, arr01, MAX, arr01);
    //SortTemplate((char*)"简单插入排序", InsertSort, arr02, MAX, arr01);
    //SortTemplate((char*)"优化插入排序", InsertSort02, arr03, MAX, arr03);
    //SortTemplate((char*)"简单冒泡排序", BubbleSort, arr04, MAX, arr01);
    //SortTemplate((char*)"优化冒泡排序", BubbleSort02, arr05, MAX, arr01);
    //SortTemplate((char*)"快速排序", QuickSort, arr06, MAX, arr00);
    SortTemplate((char*)"归并排序", MergeSort, arr07, MAX, arr00);
    //SortTemplate((char*)"堆排序(栈)", HeapSortStack, arr08, MAX, arr00);
    SortTemplate((char*)"堆排序(循环)", HeapSortLoop, arr09, MAX, arr00);

    return 0;
}

/**
 * @brief 堆排序入口
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void HeapSortLoop(int arr[], int max) {
    for (int i = max / 2 - 1; i >= 0; --i) {
        __BuildHeapLoop(arr, i, max);
    }
    __HeapSortLoop(arr, max);
}
/**
 * @brief 构建大根堆.
 * @param arr 数组
 * @param start_index 当前节点下标
 * @param max 数组长度
 *
 * @return
 */
void __BuildHeapLoop(int arr[], int start_index, int max) {
    int temp = arr[start_index];

    int child_index = (start_index + 1) * 2 - 1;
    int left_child_index = (start_index + 1) * 2 - 1;
    int right_child_index = left_child_index + 1;

    int max_child_index;
    while (left_child_index < max) {
        if(right_child_index < max) {
            max_child_index = arr[right_child_index] > arr[left_child_index] ? right_child_index : left_child_index;
        } else {
            max_child_index = left_child_index;
        }

        if (temp >= arr[max_child_index]) {
            break;
        }

        arr[start_index] = arr[max_child_index];
        start_index = max_child_index;
        left_child_index = (start_index + 1) * 2 - 1;
        right_child_index = left_child_index + 1;
    }
    arr[start_index] = temp;
}
/**
 * @brief 真正的堆排序.
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void __HeapSortLoop(int arr[], int max) {
    for (int i = max-1; i > 0; --i) {
        Swap(arr, 0, i);
        __BuildHeapLoop(arr, 0, i);
    }
}

/**
 * @brief 堆排序入口
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void HeapSortStack(int arr[], int max) {
    __InitHeapStack(arr, 0, max);
    __HeapSortStack(arr, max);
}
/**
 * @brief 初始化大根堆.
 * @param arr 数组
 * @param start_index 当前节点下标
 * @param max 数组长度
 *
 * @return
 */
void __InitHeapStack(int arr[], int start_index, int max) {
    if ((start_index + 1) * 2 > max) {
        return;
    }
    __InitHeapStack(arr, start_index * 2 + 1, max);
    __InitHeapStack(arr, start_index * 2 + 2, max);

    int right_child_index = (start_index + 1) * 2;
    int left_child_index = (start_index + 1) * 2 - 1;

    int max_child_index;
    // 比较两个节点
    if(left_child_index < max) {
        max_child_index = arr[right_child_index] > arr[left_child_index] ? right_child_index : left_child_index;
    } else {
        max_child_index = right_child_index;
    }

    // 比较父节点和子节点
    if (arr[start_index] < arr[max_child_index]) {
        Swap(arr, start_index, max_child_index);
        // 重新初始化堆
        __InitHeapStack(arr, max_child_index, max);
    }
}
/**
 * @brief 排序以后重新构建大根堆
 * @param arr 数组
 * @param start_index 当前节点下标
 * @param max 未排序数组长度
 *
 * @return
 */
void __BuildHeapStack(int arr[], int start_index, int max) {
    int right_child_index = (start_index + 1) * 2;
    int left_child_index = (start_index + 1) * 2 - 1;

    int max_child_index;
    // 比较两个节点
    if (left_child_index >= max) {
        return;
    } else if(right_child_index < max) {
        max_child_index = arr[right_child_index] > arr[left_child_index] ? right_child_index : left_child_index;
    } else {
        max_child_index = left_child_index;
    }

    // 比较父节点和子节点
    if (arr[start_index] < arr[max_child_index]) {
        Swap(arr, start_index, max_child_index);
        // 重新构建堆
        __BuildHeapStack(arr, max_child_index, max);
    }
}
/**
 * @brief 真正的堆排序
 * @param arr 数组
 * @param max 未排序数组长度
 *
 * @return
 */
void __HeapSortStack(int arr[], int max) {
    if (max == 0) {
        return;
    }
    // 堆顶 与 max-1交换位置, 重新构建堆, max = max -1;
    Swap(arr, 0, max-1);
    __BuildHeapStack(arr, 0, max-1);
    __HeapSortStack(arr, max-1);
}

/**
 * @brief 归并排序入口
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void MergeSort(int arr[], int max) {
    __MergeSort(arr, 0, max-1);
}

/**
 * @brief 真正的归并排序
 * @param arr 数组
 * @param left
 * @param right
 *
 * @return
 */
void __MergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return ;
    }
    int mid = (left + right) / 2;
    __MergeSort(arr, left, mid);
    __MergeSort(arr, mid+1, right);

    if (arr[mid] > arr[mid+1]) {
        __Merge(arr, left, mid, right);
    }
}
/**
 * @brief 合并数数组
 * @param arr 数组
 * @param left
 * @param mid
 * @param right
 *
 * @return
 */
void __Merge(int arr[], int left, int mid, int right) {
    for (int i = left; i <= right; ++i) {
        merge_temp_arr[i] = arr[i];
    }

    int left_index = left;
    int right_index = mid+1;

    for (int i = left; i <= right; ++i) {
        if (left_index > mid) {
            arr[i] = merge_temp_arr[right_index];
            right_index ++;
        } else if (right_index > right) {
            arr[i] = merge_temp_arr[left_index];
            left_index ++;
        } else if (merge_temp_arr[left_index] > merge_temp_arr[right_index]) {
            arr[i] = merge_temp_arr[right_index];
            right_index ++;
        }else {
            arr[i] = merge_temp_arr[left_index];
            left_index ++;
        }
    }
}


/**
 * @brief 快速排序入口
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void QuickSort(int arr[], int max) {
    __QuickSort(arr, 0, max-1);
}
/**
 * @brief 真正的快速排序, 递归
 * @param arr 数组
 * @param left 最小的下标
 * @param right 最大的下标
 *
 * @return
 */
void __QuickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    // 找关键pos节点
    int pos = __Partition(arr, left, right);
    // 左侧
    __QuickSort(arr, left, pos-1);
    // 右侧
    __QuickSort(arr, pos, right);
}
/**
 * @brief 排序
 * @param arr 数组
 * @param left 最小的下标
 * @param right 最大的下标
 *
 * @return 返回已排序号的下标
 */
int __Partition(int arr[], int left, int right) {
    int posIndex = rand() % (right-left+1) + left;
    int pos = arr[posIndex];

    while(left < right) {
        if (arr[left] < pos) {
            left ++;
        }

        if (arr[right] > pos) {
            right --;
        }
        Swap(arr, left, right);
    }
    arr[left] = pos;
    return left;
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

/**
 * @brief 比较函数
 * @param a
 * @param b
 *
 * @return
 */
int __QsortComp(const void* a,const void* b) {
    return *(int*)a-*(int*)b;
}
/**
 * @brief 库Qsort
 * @param arr 数组
 * @param max 数组长度
 *
 * @return
 */
void Qsort(int arr[], int max) {
    qsort(arr, max, sizeof(int), __QsortComp);
}

