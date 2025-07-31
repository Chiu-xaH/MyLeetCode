void moveZeroes(int* nums, int numsSize) {
    for(int j = 0;j < numsSize - 1;j++) {
        for(int i = 0;i < numsSize - 1;i++) {
            int left = nums[i];
            int right = nums[i+1];
            if(left == 0 && right != 0) {
                // 交换
                nums[i] = right;
                nums[i+1] = left;
            }
        }
    } 
}