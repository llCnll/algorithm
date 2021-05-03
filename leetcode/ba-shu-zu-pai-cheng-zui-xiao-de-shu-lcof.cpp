#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int getDigit(int num, int * num_arr) {
    if (num == 0) {
        num_arr[0] = 0;
        return 1;
    }
    int count = 0;
    while(num) {
        num_arr[count++] = num % 10;
        num /= 10;
    }
    return count;
}

int __QsortComp(const void * a, const void * b) {
    int temp_a = *(int*)a;
    int temp_b = *(int*)b;
    // 0低位 --> 高位
    int * temp_a_num = (int*)calloc(11*2, sizeof(int));
    int * temp_b_num = (int*)calloc(11*2, sizeof(int));
    // 判断位数
    int digit_a = getDigit(temp_a, temp_a_num);
    int digit_b = getDigit(temp_b, temp_b_num);
    if (temp_a == temp_b) {
        return 0;
    }
    // 位数相同, 小的在前面
    if (digit_a == digit_b) {
        //printf("0 %d - %d\n", temp_a, temp_b);
        return temp_a - temp_b;
    }

    for (int i = 0; i < min(digit_a, digit_b); ++i) {
        // 当前位小的值在前面
        if (temp_a_num[digit_a-1-i] != temp_b_num[digit_b-1-i]) {
            //printf("5 %d - %d\n", temp_a, temp_b);
            return temp_a_num[digit_a-1-i] - temp_b_num[digit_b-1-i];
        }
    }

    // 将两个数拼起来, 比较大小
    for (int i = 0; i < digit_a; ++i) {
        temp_b_num[digit_b+i] = temp_a_num[i];
    }
    for (int i = 0; i < digit_b; ++i) {
        temp_a_num[digit_a+i] = temp_b_num[i];
    }
    for (int i = digit_a+digit_b-1; i >= 0; --i) {
        if (temp_a_num[i] > temp_b_num[i]) {
            //printf("1 %d > %d\n", temp_a, temp_b);
            return -1;
        } else if (temp_a_num[i] < temp_b_num[i]) {
            //printf("2 %d < %d\n", temp_a, temp_b);
            return 1;
        }
    }
    free(temp_a_num);
    free(temp_b_num);
    //printf("3 %d == %d\n", temp_a, temp_b);
    return 0;
}

// 121 12未处理
int __QsortComp2(const void * a, const void * b) {
    int temp_a = *(int*)a;
    int temp_b = *(int*)b;
    // 0低位 --> 高位
    int * temp_a_num = (int*)calloc(11, sizeof(int));
    int * temp_b_num = (int*)calloc(11, sizeof(int));
    // 判断位数
    int digit_a = getDigit(temp_a, temp_a_num);
    int digit_b = getDigit(temp_b, temp_b_num);
    if (temp_a == temp_b) {
        return 0;
    }
    // 位数相同, 小的在前面
    if (digit_a == digit_b) {
        printf("0 %d - %d\n", temp_a, temp_b);
        return temp_a - temp_b;
    }
    // 从高位(下标digit_a-1)-->低位(下标0)
    for (int i = 0; i < max(digit_a, digit_b); ++i) {
        // 位数少, 且另一个数的下一位相比
        if (digit_a - 1 - i < 0 && (temp_a_num[digit_a-1] <= temp_b_num[digit_b-digit_a-1])) {
            printf("1 %d < %d\n", temp_a, temp_b);
            return -1;
        } else if (digit_a - 1 - i < 0 && (temp_a_num[digit_a-1] > temp_b_num[digit_b-digit_a-1])){
            printf("2 %d > %d\n", temp_a, temp_b);
            return 1;
        } else if (digit_b - 1 - i < 0 && (temp_b_num[digit_b-1] <= temp_a_num[digit_a-digit_b-1])) {
            printf("3 %d > %d\n", temp_a, temp_b);
            return 1;
        } else if (digit_b - 1 - i < 0 && (temp_b_num[digit_b-1] > temp_a_num[digit_a-digit_b-1])){
            printf("4 %d < %d\n", temp_a, temp_b);
            return -1;
        }
        // 当前位小的值在前面
        if (temp_a_num[digit_a-1-i] != temp_b_num[digit_b-1-i]) {
            printf("5 %d - %d\n", temp_a, temp_b);
            return temp_a_num[digit_a-1-i] - temp_b_num[digit_b-1-i];
        }
    }
    free(temp_a_num);
    free(temp_a_num);
    return 0;
}

char* minNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), __QsortComp);

    char * result = (char*)calloc(numsSize*10, sizeof(char));

    char * temp_num = (char*)calloc(10, sizeof(char));
    for(int i = 0 ; i < numsSize; ++i) {
        sprintf(temp_num, "%d", nums[i]);
        strcat(result, temp_num);
    }
    return result;
}

int main() {

    int nums[] = {3, 30, 34, 5, 9};
    int numsSize = 5;

    printf("%s\n", minNumber(nums, numsSize));

    for(int i = 0; i < numsSize; ++i) {
        printf("%d\t", nums[i]);
    }

    putchar('\n');

    int nums2[] = {2260, 2};
    int numsSize2 = 2;

    printf("%s\n", minNumber(nums2, numsSize2));

    for(int i = 0; i < numsSize2; ++i) {
        printf("%d\t", nums2[i]);
    }

    putchar('\n');

    int nums4[] = {121, 12};
    int numsSize4 = 2;

    printf("%s\n", minNumber(nums4, numsSize4));

    for(int i = 0; i < numsSize4; ++i) {
        printf("%d\t", nums4[i]);
    }

    putchar('\n');

   //int nums3[] = {4704,6306,9385,7536,3462,4798,5422,5529,8070,6241,9094,7846,663,6221,216,6758,8353,3650,3836,8183,3516,5909,6744,1548,5712,2281,3664,7100,6698,7321,4980,8937,3163,5784,3298,9890,1090,7605,1380,1147,1495,3699,9448,5208,9456,3846,3567,6856,2000,3575,7205,2697,5972,7471,1763,1143,1417,6038,2313,6554,9026,8107,9827,7982,9685,3905,8939,1048,282,7423,6327,2970,4453,5460,3399,9533,914,3932,192,3084,6806,273,4283,2060,5682,2,2362,4812,7032,810,2465,6511,213,2362,3021,2745,3636,6265,1518,8398};
   //int numsSize3 = 100;

   //printf("%s\n", minNumber(nums3, numsSize3));

   //for(int i = 0; i < numsSize3; ++i) {
   //    printf("%d\t", nums3[i]);
   //}

    return 0;
}

