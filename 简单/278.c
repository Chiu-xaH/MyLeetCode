// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start = 1,end = n;
    while(start < end) {
        int mid = start+(end-start)/2;
        if(isBadVersion(mid) && !isBadVersion(mid-1)) {
            return mid;
        }
        if(isBadVersion(mid)) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return start;
}