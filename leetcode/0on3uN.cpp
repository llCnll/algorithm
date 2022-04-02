#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define IP_MAX 255
#define LOC_MAX 4

int size = 0;
char temp[20];

void __createIps(char ** ans, char * s, int s_index, int ip_nums[], int localtion, bool carry) {
    if (localtion > LOC_MAX) return ;

    // printf("\t当前字符: %d, %c, localtion: %d, carry: %d\n", s_index, s[s_index], localtion, carry);

    if (strlen(s) == s_index && ((localtion == 3&&!carry) || (localtion == 4 && carry)) && (!carry || '0' == s[s_index-1])) {
        sprintf(temp, "%d.%d.%d.%d" , ip_nums[0], ip_nums[1], ip_nums[2], ip_nums[3]);
        ans[size] = (char*)malloc(sizeof(char) * 20);
        strcpy(ans[size], temp);
        size++;
        // printf("正确的IP: %s\n", temp);
    }
    // else if (strlen(s) == s_index) {
    //     printf("location: %d, 错误的IP: ", localtion);
    //     for (int i = 0; i <= localtion; ++i) {
    //         printf("%d ", ip_nums[i]);
    //     }
    //     putchar('\n');
    // }

    if (strlen(s) <= s_index) return ;


    int i = s_index;
    if (ip_nums[localtion] == 0 && s[i] == '0') {
        // printf("进位, index: %d, localtion: %d, %d, localtion+1: %d, %d\n", i, localtion,  ip_nums[localtion], localtion+1, ip_nums[localtion+1]);
        __createIps(ans, s, i+1, ip_nums, localtion+1, true);
        // ip_nums[localtion+1] = 0;
    } else {
        ip_nums[localtion] =  ip_nums[localtion] * 10 + s[i] - '0';
        if (ip_nums[localtion] > IP_MAX) {
            //ip_nums[localtion] /= 10;
            //ip_nums[localtion+1] = s[i] - '0';
            ////printf("%d\n", ip_nums[localtion+1]);
            //__createIps(ans, s, i+1, ip_nums, localtion+1);
            //ip_nums[localtion+1] = 0;
            // printf("超过IP_MAX, index: %d, localtion: %d, %d\n", i, localtion, ip_nums[localtion]);
            //return ;
        } else {
            // printf("正常, index: %d, localtion: %d, %d\n", i, localtion, ip_nums[localtion]);
            __createIps(ans, s, i+1, ip_nums, localtion, false);

            // printf("进位, index: %d, localtion: %d, %d, localtion+1: %d, %d\n", i, localtion,  ip_nums[localtion], localtion+1, ip_nums[localtion+1]);
            __createIps(ans, s, i+1, ip_nums, localtion+1, true);
        }
        ip_nums[localtion] /= 10;
    }
    return ;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    int length = strlen(s);
    if (length > 12) {
        *returnSize = 0;
        return NULL;
    }

    char ** ans = (char**)malloc(sizeof(char*) * 1000);
    int ip_nums[5]  = {0,0,0,0};

    __createIps(ans, s, 0, ip_nums, 0, false);

    *returnSize = size;

    return ans;
}

int main() {

    char s[] = "25525511135";
    // char s[] = "01111";
    // char s[] = "0001";

    int size;

    char ** ans = restoreIpAddresses(s, &size);

    printf("size: %d\n", size);
    for (int i = 0; i < size; ++i) {
        printf("%s\n", ans[i]);
    }

    return 0;
}

