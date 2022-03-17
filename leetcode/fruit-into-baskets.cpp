#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX 10010
#define max(a,b) (a) > (b) ? (a) : (b)

int arr[MAX];

int totalFruit(int* fruits, int fruitsSize){
    memset(arr, 0, sizeof(int) * MAX);

    int category = 0;
    int ans = 0;

    // start起始位置
    // end 即将插入的位置
    int start = 0, end = 0;
    while (true) {
        // 当前添加的种类为空
        if (arr[fruits[end]] == 0) {
            // 不允许添加
            if (category == 2) {
                // 需要进行释放 arr[start]
                while (--arr[fruits[start++]]);
                category--;
            } else {
                arr[fruits[end]]++;
                category++;
                end ++;
                ans = max(end-start, ans);
            }
        } else {
            arr[fruits[end++]]++;
            ans = max(end-start, ans);
        }

        // printf("start = %d, end = %d, category = %d\n", start, end, category);

        if (end == fruitsSize) {
            return ans;
        }
    }
    return 0;
}

int main() {

    int fruits[] = {3,3,3,1,2,1,1,2,3,3,4};
    int size = 11;

    printf("%d\n", totalFruit(fruits, size));

    return 0;
}

