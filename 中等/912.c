/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void swap(int* nums,int i,int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void quick(int* nums,int start,int end) {
    // 判断结束
    if(end <= start) {
        return;
    }
    // 改进 随机化枢轴
    int pivotIndex = start + rand() % (end - start + 1);
    swap(nums, start, pivotIndex);
    int center = nums[start];
    // 左右边界
    int left = start;
    int right = end;
    while(left <= right) {
        while(nums[right] > center) {
            right--;
        }
        while(nums[left] < center) {
            left++;
        }
        if (left <= right) {
            // 交换
            swap(nums,left,right);
            left++;
            right--;
        }
    }
    // 递归处理
    quick(nums,start,right);
    quick(nums,left,end);
}

void quickSort(int* nums,int numsSize) {
    quick(nums,0,numsSize-1);
}


int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    quickSort(nums,numsSize);
    return nums;
}