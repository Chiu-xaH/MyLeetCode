void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int ptr1 = m - 1;       
    int ptr2 = n - 1;       
    int tail = m + n - 1;  

    while (ptr1 >= 0 && ptr2 >= 0) {
        if (nums1[ptr1] > nums2[ptr2]) {
            nums1[tail] = nums1[ptr1];
            ptr1--;
        } else {
            nums1[tail] = nums2[ptr2];
            ptr2--;
        }
        tail--;
    }

    // nums2 还有剩余
    while (ptr2 >= 0) {
        nums1[tail] = nums2[ptr2];
        ptr2--;
        tail--;
    }
}