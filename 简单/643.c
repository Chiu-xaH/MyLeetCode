int getPtrEnd(int k,int start) {
    return start + k - 1;
}

double findMaxAverage(int* nums, int numsSize, int k) {
    int ptrStart = 0;
    int ptrEnd = getPtrEnd(k,ptrStart);

    double totalValue = 0;
    for(int i = ptrStart;i <= ptrEnd;i++) {
        totalValue += nums[i];
    }
    double maxVaule = totalValue;

    while(ptrEnd + 1 <= numsSize - 1) {
        totalValue = totalValue - nums[ptrStart] + nums[ptrEnd+1];
        if(maxVaule < totalValue) {
            maxVaule = totalValue;
        }
        ptrStart++;
        ptrEnd++;
    }
    double result = maxVaule / k;
    return result;
}