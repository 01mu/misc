#include "stdio.h"
#include "stdlib.h"

char * getSmallestString(int n, int k) {
    char * smallest = malloc((sizeof(char) * n) + 1);
    int hold[n], last, i;

    smallest[0] = '\0';

    for(i = 0; i < n; i++) {
        if(k >= 26) {
            hold[i] = 26;
            last = i;
            k -= 26;
        } else {
            if(k > 0) {
                hold[i] = k;

                if(k != 1) {
                    last = i;
                }

                k = 0;
            } else {
                hold[i] = 1;
                hold[last] -= 1;
            }
        }
    }

    for(i = n - 1; i >= 0; i--) {
        sprintf(smallest, "%s%c", smallest, hold[i] + 96);
    }

    return smallest;
}

int main()
{
    int n = 3, k = 27;
    char * smallest = getSmallestString(n, k);

    printf("%s\n", smallest);
    free(smallest);
}
