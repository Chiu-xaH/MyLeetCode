void deleteEle(int *nums,int *numsSize,int place) {
    for (int i = place; i < *numsSize - 1; i++) {
        nums[i] = nums[i + 1];
    }
    (*numsSize)--;
}

bool isSorted(int *nums,int numsSize) {
    for (int ptr = 0; ptr < numsSize - 1; ptr++) {
        if (nums[ptr] >= nums[ptr + 1]) {
            return false;
        }
    }
    return true;
}

bool canBeIncreasing(int* nums, int numsSize) {
    int left = 0,right = numsSize-1;
     // 在数组中找到不符合递增顺序的位置
    while (left < right) {
        if (nums[left] < nums[left + 1]) {
            left++;
        } else if (nums[right] > nums[right - 1]) {
            right--;
        } else {
            break;
        }
    }

    // 如果left == right，说明整个数组已经是递增的
    if (left == right) {
        return true;
    }

    //判断删left还是right
    // 创建两个临时数组分别进行删除操作
    int* temp1 = (int*)malloc(numsSize * sizeof(int));
    int* temp2 = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp1[i] = nums[i];
        temp2[i] = nums[i];
    }

    // 尝试删除left位置的元素
    int tempSize1 = numsSize;
    deleteEle(temp1, &tempSize1, left);
    if (isSorted(temp1, tempSize1)) {
        free(temp1);
        free(temp2);
        return true;
    }

    // 尝试删除right位置的元素
    int tempSize2 = numsSize;
    deleteEle(temp2, &tempSize2, right);
    bool result = isSorted(temp2, tempSize2);
    
    free(temp1);
    free(temp2);
    
    return result;
}