#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) return false;

    int * count = (int*)calloc(100, sizeof(int));

    for (int i = 0; i < strlen(s); ++i) count[s[i]-'A']++;

    for (int i = 0; i < strlen(t); ++i) count[t[i]-'A']--;

    for (int i = 0; i < 100; i++) {
        if (count[i] != 0) {
            free(count);
            return false;
        }
    }
    free(count);
    return true;
}

int main() {

    char s[] = "cra";
    char t[] = "car";

    printf("%d\n", isAnagram(s, t));

    return 0;
}

