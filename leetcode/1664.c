#include "stdio.h"
#include "stdlib.h"

int waysToMakeFair(int * nums, int numsSize) {
    int i;
    int odd_total = 0, even_total = 0;
    int odd_r, even_r;
    int odd_l = 0, even_l = 0;
    int even_sum, odd_sum;
    int count = 0;

    for(i = 0; i < numsSize; i++) {
        if(i % 2 == 0) {
            even_total += nums[i];
        } else {
            odd_total += nums[i];
        }
    }

    for(i = 0; i < numsSize; i++) {
        if(i % 2 == 0) {
            even_l += nums[i];
        } else {
            odd_l += nums[i];
        }

        odd_r = odd_total - odd_l;
        even_r = even_total - even_l;

        if(i % 2 == 0) {
            even_sum = (even_l - nums[i]) + odd_r;
            odd_sum = odd_l + even_r;
        } else {
            even_sum = (odd_l - nums[i]) + even_r;
            odd_sum = even_l + odd_r;
        }

        if(even_sum == odd_sum) {
            count += 1;
        }
    }

    return count;
}

int main()
{
    int arr[4] = {2, 1, 6, 4};
    int c = 4;

    printf("%i\n", waysToMakeFair(arr, c));
}
