int findMin(int* nums, int numsSize) {
    if (numsSize == 0) return -1;

    // 找旋转点（最小值下标）
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}