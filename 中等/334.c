bool increasingTriplet(int* nums, int numsSize) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i];  // 找到更小的first
        } else if (nums[i] <= second) {
            second = nums[i];  // 找到比first大的second
        } else {
            // 有比second更大的数
            return true;
        }
    }
    return false;
}