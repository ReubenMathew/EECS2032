#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

int main(void) {

    float nums[6] = {0.5,.25,.125,0.0625,0.03125,0.015625};

    float ratio = nums[1] / nums[0];

    int geo = TRUE;

    int i;

    for (i = 0; i < 6-1; ++i){
        printf("%f\n",nums[i]);
        if(nums[i+1] / ratio != nums[i])
            geo = FALSE;
    }

    printf("%d\n",geo);

    return 0;

}
