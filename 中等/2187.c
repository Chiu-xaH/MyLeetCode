long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long start = 1,end = (long long)totalTrips*time[0];
    while(start < end) {
        long long sum = 0,mid = (start+end)/2;
        for(int i = 0;i < timeSize;i++) {
            sum += (mid / time[i]);
        }
        // 如果在 mid 时间内能完成的行程数 >= totalTrips，尝试缩小时间
        if (sum >= totalTrips) {
            end = mid;
        } else {
            start = mid + 1;  // mid 不足以完成行程，增加时间
        }
    }
    return start;
}