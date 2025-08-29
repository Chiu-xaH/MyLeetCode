// void rotate(int* nums, int numsSize, int k) {
//     for(int i = 1;i <= k;i++) {
//         int index = numsSize-1;
//         int value = nums[index];
//         // 整体右移
//         for(int j = index;j-1 >= 0;j--) {
//             nums[j] = nums[j-1];
//         }
//         // 插入
//         nums[0] = value;
//     }
// }
// 三次反转法
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;
    k %= numsSize; // 防止 k > numsSize
    if (k == 0) return;

    // 1. 反转整个数组
    reverse(nums, 0, numsSize - 1);
    // 2. 反转前 k 个
    reverse(nums, 0, k - 1);
    // 3. 反转后 n-k 个
    reverse(nums, k, numsSize - 1);
}
