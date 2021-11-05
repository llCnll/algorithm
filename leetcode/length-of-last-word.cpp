#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int lengthOfLastWord(char * s){
    int size = strlen(s);
    int count = 0;

    for (int i = size-1; i >= 0; i--) {
        if (s[i] == ' ' && count != 0) {
            break;
        }
        if (s[i] == ' ' && count == 0) {
            continue;
        }
        count ++;
    }

    return count;
}

int main() {

    char str[] = "abcd edf efg eee     eeeee  ";

    printf("%d\n", lengthOfLastWord(str));

    return 0;
}

