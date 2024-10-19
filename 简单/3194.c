double findAndRemove(int* nums,int numsSize) {
    int max = -1,min = -1;
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] != -1) {
            if (max == -1 || nums[i] > nums[max]) {
                max = i;
            }
            if (min == -1 || nums[i] < nums[min]) {
                min = i;
            }
        }
    }
    
    double average = (nums[max] + nums[min]) / 2.0;
    nums[max] = -1;
    nums[min] = -1;
    return average;
}

void add(double* arr,int *size,double key) {
    arr[*size] = key;
    (*size)++;
}

double findMin(double* arr,int size) {
    int min = 0;
    for(int i = 0;i < size;i++) {
        if(arr[i] < arr[min]) {
            min = i;
        }
    }
    return arr[min];
}

double minimumAverage(int* nums, int numsSize) {
    double arr[50] = { 0.0 };
    int size = 0;
    int times = 0;
    while(times < numsSize / 2) {
        add(arr,&size,findAndRemove(nums,numsSize));
        times++;
    }
    return findMin(arr,size);
}