int BinarySearch(int *arr,int start,int end,int key) {
    if (start >= end) {
        if(key > arr[start])
        return start+1;
        else  return start;
    }
    int mid = (start+end)/2;
    if(key < arr[mid]) {
        return BinarySearch(arr,start,mid-1,key);
    } else if(key > arr[mid]) {
        return BinarySearch(arr,mid+1,end,key);
    } else {
        return mid;
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    return BinarySearch(nums,0,numsSize-1,target);
}