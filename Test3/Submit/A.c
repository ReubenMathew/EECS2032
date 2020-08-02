#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

int main(void) {

    int one, two,i;
    
    scanf("%d",&one);
    int nums1[one];

    for(i = 0; i < one; i++){
        int temp;
        scanf("%d",&temp);
        nums1[i] = temp;
    }

    scanf("%d",&two);
    int nums2[two];
    for(i = 0; i < two; i++){
        int temp;
        scanf("%d",&temp);
        nums2[i] = temp;
    }


    for(i = 0; i < one; i++){
        printf("%d ",nums1[i]);
    }
    printf("\n");
    for(i = 0; i < two; i++){
        printf("%d ",nums2[i]);
    }
    printf("\n");

    int n;
    scanf("%d",&n);
    
    if(n > one || n > two){
        printf("INVALID\n");
        return 0;
    }
    
    int larger = TRUE, equal = TRUE, smaller = TRUE;
    for(i = 0; i < n; i++){
        if(nums1[i] != nums2[i])
            equal = FALSE;  
        if(nums1[i] >= nums2[i])
            smaller = FALSE;
        if(nums1[i] <= nums2[i])
            larger = FALSE;
    }

    if(larger)
        printf("LARGER\n");
    else if(smaller)
        printf("SMALLER\n");
    else if(equal)
        printf("EQUAL\n");
    else
        printf("NONE\n");

    return 0;

}
