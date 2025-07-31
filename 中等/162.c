void binary(int *nums,int left,int right,int *result) {
    if(left == right) {
        *result = left;
        return;
    }
    int mid = (left + right) / 2;
    int val = nums[mid];
    if(val > nums[mid+1]) {
        //左侧
        binary(nums,left,mid,result);
    } else {
        binary(nums,mid+1,right,result);
    }
}

int findPeakElement(int* nums, int numsSize) {
    int result = 0;
    binary(nums,0,numsSize-1,&result);
    return result;
}