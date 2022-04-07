#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char nextGreatestLetter(char* letters, int lettersSize, char target){
    if (target >= letters[lettersSize-1])
        return letters[0];

    int start = 0, end = lettersSize - 1;

    while (start <= end) {
        int mid = start + (end-start)/2;
        if (letters[mid] > target) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return letters[start];
}

int main() {

    char letters[] = {'c', 'f', 'j'};
    int letterSize = 3;

    printf("%c\n", nextGreatestLetter(letters, letterSize, 'f'));

    return 0;
}

