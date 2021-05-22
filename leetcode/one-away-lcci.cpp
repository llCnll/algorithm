#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool insert_char(char* first, char* second, int first_index, int second_index) {
    if (strlen(first)+1 != strlen(second)) return false;
    while (first_index < strlen(first)) {
        if (first[first_index++] != second[second_index++]) {
            return false;
        }
    }
    return true;
}

bool replace_char(char* first, char* second, int first_index, int second_index) {
    if (strlen(first) != strlen(second)) return false;
    while (first_index < strlen(first)) {
        if (first[first_index++] != second[second_index++]) {
            return false;
        }
    }
    return true;
}

bool delete_char(char* first, char* second, int first_index, int second_index) {
    if (strlen(first) != strlen(second)+1) return false;
    while (first_index < strlen(first)) {
        if (first[first_index++] != second[second_index++]) {
            return false;
        }
    }
    return true;
}

bool oneEditAway(char* first, char* second){
    int first_length = 0;
    int second_length = 0;

    if (first != NULL) first_length = strlen(first);
    if (second != NULL) second_length = strlen(second);
    if (abs(first_length - second_length) > 1) return false;

    bool can_do = true;
    for (int i = 0; i < first_length; ++i) {
        if (first[i] != second[i]) {
                return insert_char(first, second, i, i+1) || delete_char(first, second, i+1, i) || replace_char(first, second, i+1, i+1);
        }
    }
    return true;
}

int main() {

    char s1[] = "pale";
    char s2[] = "ple";

    printf("%d\n", oneEditAway(s1, s2));

    return 0;
}

