class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] newNums = new int[nums.length];
        for (int i = 0; i < newNums.length; i++) {
            newNums[i] = 1;
        }

        // 从右向左
        int rightMulValue = 1;
        int right = nums.length - 1;
        while (right >= 0) {
            newNums[right] *= rightMulValue;
            rightMulValue *= nums[right];
            right--;
        }

        // 从左向右
        int leftMulValue = 1;
        int left = 0;
        while (left < nums.length) {
            newNums[left] *= leftMulValue;
            leftMulValue *= nums[left];
            left++;
        }

        return newNums;
    }
}
