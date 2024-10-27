int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int count = 0;
    for(int i = 0;i < arrSize;i++) {
        for(int j = i+1;j < arrSize;j++) {
            for(int k = j+1;k < arrSize;k++) {
                if(fabs(arr[i] - arr[j]) <= a && fabs(arr[j] - arr[k]) <= b && fabs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }
    return count;
}