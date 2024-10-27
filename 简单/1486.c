int xorOperation(int n, int start) {
    int res = start;
    for(int i = 1;i < n;i++) {
        int x = start + 2*i;
        res ^= x;
    }
    return res;
}