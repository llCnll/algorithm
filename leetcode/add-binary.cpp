#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void swap(char * ans, int i, int j) {
    char temp = ans[i];
    ans[i] = ans[j];
    ans[j] = temp;
}

char * addBinary(char * a, char * b){
    int length_a = strlen(a);
    int length_b = strlen(b);

    int returnSize = max(length_b, length_a);
    char* ans = (char*)calloc(returnSize+1, sizeof(char));

    int flag = 0;
    for (int i = 0; i < returnSize; ++i) {
        if(i < length_a && i < length_b) {
            ans[i] = ((a[length_a-i-1]-'0') ^ (b[length_b-i-1]-'0') ^ flag) + '0';
            flag = (a[length_a-i-1]-'0' + b[length_b-i-1]-'0' + flag) > 1;
        }
    }

    if (length_a == length_b) {

    }else if (length_a > length_b) {
        for (int i = length_b; i < length_a; ++i) {
            ans[i] = ((a[length_a-i-1]-'0') ^ flag) + '0';
            flag = (a[length_a-i-1]-'0' + flag) > 1;
        }
    } else {
        for (int i = length_a; i < length_b; ++i) {
            ans[i] = ((b[length_b-i-1]-'0') ^ flag) + '0';
            flag = (b[length_b-i-1]-'0' + flag) > 1;
        }
    }
    if (flag) {
        ans[returnSize++] = '1';
    }

    for (int i = 0; i < returnSize/2; ++i) {
        swap(ans, i, returnSize-i-1);
    }
    return ans;
}

int main() {
    char a[] = "1";
    char b[] = "11";
    printf("%s\n", addBinary(a, b));

    return 0;
}

