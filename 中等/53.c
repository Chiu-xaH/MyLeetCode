int max(int a,int b) {
    return a > b ? a : b;
}

int Kadane(int array[],int size) {
    int maxEndingHere = array[0];
    int maxSoFar = array[0];
    for(int i = 1;i < size;i++) {
        maxEndingHere = max(maxEndingHere+array[i],array[i]);
        maxSoFar = max(maxSoFar,maxEndingHere);
    }
    return maxSoFar;
}
int maxSubArray(int* nums, int numsSize) {
    return Kadane(nums,numsSize);
}