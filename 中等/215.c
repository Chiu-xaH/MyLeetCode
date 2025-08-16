
int quickSort(int* nums,int left,int right,int k) {
    if(left == right) {
        return nums[k];
    }
    int p = nums[left];
    int i = left-1;
    int j = right+1;
    while(i < j) {
        do i++;while(nums[i] < p);
        do j--;while(nums[j] > p);
        if(i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    if(k <= j) {
        return quickSort(nums,left,j,k);
    } else {
        return quickSort(nums,j+1,right,k);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSort(nums,0,numsSize-1,numsSize - k);
}