#include <stdio.h>

void moveDirction(int *nums,int moveDirction,int place,int size) {
    for(int i = place;i < size;i++) {
        nums[i-moveDirction] = nums[i];
    }
    for(int i = 0;i < moveDirction;i++) {
        nums[size-1-i] = 65535;
    }
}

int removeDuplicates(int* nums, int numsSize) {
    int ptr = 0,ptrRight = 1,count = 1;
    while(ptrRight < numsSize &&nums[ptrRight] != 65535) {
        int same = 0;
        while(ptrRight < numsSize && nums[ptrRight] == nums[ptr]) {
            same++;
            ptrRight++;
        }
        //左移动same个单位
        if(same > 0) {
            moveDirction(nums,same,ptrRight,numsSize);
        }
        count++;
        ptr++;
        ptrRight = ptr+1;
        if(nums[ptr] == 65535) count--;
    }
    return count;
}

int main() {
    int arr[] = {1,1};
    int size = 2;
    int s = removeDuplicates(arr,size);
    for(int i =0;i < s;i++)
    printf("%d ",arr[i]);
}