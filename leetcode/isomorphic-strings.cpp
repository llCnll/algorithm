#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MIN -300
int mapps_a[300];
int mapps_b[300];

bool isIsomorphic(char * s, char * t){
    for (int i = 0; i < 300; ++i) mapps_a[i] = MIN;
    for (int i = 0; i < 300; ++i) mapps_b[i] = MIN;
    for (int i = 0; i < strlen(s); ++i) {
        if(mapps_a[s[i]] == MIN && mapps_b[t[i]] == MIN) {
            mapps_a[s[i]] = s[i]-t[i];
            mapps_b[t[i]] = t[i]-s[i];
        } else {
            if ((s[i] - t[i] != mapps_a[s[i]]) || (t[i] - s[i] != mapps_b[t[i]])) return false;
        }
    }
    return true;
}

int main() {
    char s[] = "paper";
    char t[] = "title";

    printf("%d\n", isIsomorphic(s, t));

    return 0;
}

