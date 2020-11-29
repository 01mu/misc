#include "stdio.h"
#include "stdlib.h"

char * getSmallestString(int n, int k) {
    char * smallest = malloc((sizeof(char) * n) + 1);
    int arr[n], dec, i;

    smallest[0] = '\0';

    for(i = 0; i < n; i++) {
        if(k > 0) {
            if(k >= 26) {
                arr[i] = 26;
            } else {
                arr[i] = k;
            }

            if(k > 1) {
                dec = i;
            }

            k -= 26;
        } else {
            arr[i] = 1;
            arr[dec] -= 1;

            if(arr[dec] == 1) {
                dec--;
            }
        }
    }

    for(i = n - 1; i >= 0; i--) {
        sprintf(smallest, "%s%c", smallest, arr[i] + 96);
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
