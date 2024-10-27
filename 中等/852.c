int peakIndexInMountainArray(int* arr, int arrSize) {
    int start = 0,end = arrSize-1;
    
    while(start <= end) {
        int mid = (start+end) / 2;
        if (arr[mid] < arr[mid+1]) {
            start = mid + 1;
        } else if (arr[mid] < arr[mid-1]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return start;
}