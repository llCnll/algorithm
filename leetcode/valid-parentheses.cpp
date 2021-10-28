#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

bool isValid(char * s){
    int length = strlen(s);
    char * stack = (char*)calloc(length, sizeof(char));
    int top = 0;

    for (int i = 0; i < length; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
        } else if (s[i] == ')') {
            if (top <= 0) {
                return false;
            }
            if (stack[top-1] != '(') {
                return false;
            }
            top --;
        } else if (s[i] == '}') {
            if (top <= 0) {
                return false;
            }
            if (stack[top-1] != '{') {
                return false;
            }
            top --;
        } else if (s[i] == ']') {
            if (top <= 0) {
                return false;
            }
            if (stack[top-1] != '[') {
                return false;
            }
            top --;
        }
    }
    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {

    char s[] = "({})(()";

    printf("%d\n", isValid(s));

    return 0;
}

