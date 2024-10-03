int mySqrt(int x) {
    int res = 0;
    for(long i = 0;i <= x/2+1;i++) {
        if(i*i <= x) {
            res = i;
        } else {
            return res;
        }
    }
    return res;
}