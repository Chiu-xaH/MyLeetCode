int search(int* nums, int numsSize, int target) {
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
    int pivot = left;

    // 判断 target 落在哪一段
    left = 0, right = numsSize - 1;
    if (target >= nums[pivot] && target <= nums[numsSize - 1]) {
        left = pivot;
    } else {
        right = pivot - 1;
    }

    // 在对应区间二分查找
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
// 力扣33 思路 找分界点 然后再两边（均为递增序列）进行二分查找