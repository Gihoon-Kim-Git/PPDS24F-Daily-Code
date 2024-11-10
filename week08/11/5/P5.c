#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMin(int* nums, int numsSize) {
    int start = 0;
    int end = numsSize-1;

    while(start < end){
        int mid = (start+end) / 2;
        //mid가 sorting된 어레이 기준 큰 값에 위치
        if (nums[mid] > nums[end]){
            start = mid+1;
        }
        //mid가 sorting된 어레이 기준 작은 값에 위치하고, start는 큰 값에 위치
        else if(nums[mid] < nums[start]){
            end = mid;
        }
        //이미 start가 최소값이거나 mid랑 start,end가 중복값일 때
        else{
            end -= 1;
        }
    }
    return nums[start];
}