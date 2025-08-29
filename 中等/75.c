// void swap(int* nums,int a,int b) {
//     int temp = nums[a];
//     nums[a] = nums[b];
//     nums[b] = temp;
// }

// void sortColors(int* nums, int numsSize) {
//     int left = 0,right = numsSize-1;
//     while(left <= right) {
//         while(nums[left] == 0) {
//             left++;
//         }
//         while(nums[right] >= 1) {
//             right--;
//         }
//         swap(nums,left,right);
//     }
//     left = right;
//     right = numsSize-1;
//     while(left <= right) {
//         while(nums[left] == 1) {
//             left++;
//         }
//         while(nums[right] == 2) {
//             right--;
//         }
//         swap(nums,left,right);
//     }
// }

void sortColors(int* nums, int numsSize) {
    int count0 = 0,count1 = 0,count2 = 0;
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] == 0) {
            count0++;
        } else if(nums[i] == 1) {
            count1++;
        } else if(nums[i] == 2) {
            count2++;
        }
    }
    int i = 0;
    for (; i < count0; i++) nums[i] = 0;
    for (; i < count0 + count1; i++) nums[i] = 1;
    for (; i < numsSize; i++) nums[i] = 2;
}