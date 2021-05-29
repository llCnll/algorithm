#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool isFlipedString(char* s1, char* s2){
    if (strlen(s1) != strlen(s2)) return false;
    char * s = (char*)calloc(strlen(s2)*2, sizeof(int));
    strcpy(s, s2);
    strcat(s, s2);
    return strstr(s, s1) == NULL ? false : true;
}

int main() {

    char s1[] = "waterbottle";
    char s2[] = "erbottlewat";

    printf("%d\n", isFlipedString(s1, s2));

    return 0;
}


