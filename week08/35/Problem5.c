#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize) {
    int front = 0;
    int rear = numsSize - 1;
    int temp;

    if(numsSize==1)
    {
        return nums[numsSize-1];
    }

    while(front < rear)
    {
        if(front == rear - 1)
        {
            temp = nums[front] < nums[rear] ? nums[front] : nums[rear]; 
        }
        if(nums[front]>=nums[rear])
        {
            front++;
        }
        else
        {
            rear--;
        }
    }
    return temp;
}
/*
// gpt ver
int findMin(int* nums, int numsSize) {
    int front = 0;
    int rear = numsSize - 1;

    while (front < rear) {
        int mid = front + (rear - front) / 2;

        if (nums[mid] > nums[rear]) {
            // 최소값은 오른쪽에 있음
            front = mid + 1;
        } else if (nums[mid] < nums[rear]) {
            // 최소값은 왼쪽에 있음
            rear = mid;
        } else {
            // nums[mid] == nums[rear], rear를 감소시켜서 중복 제거
            rear--;
        }
    }

    return nums[front]; // 최소값
}

*/