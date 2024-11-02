int min(int a,int b) {
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int f1 = 0,f0 = 0;
    for(int i = 0;i < costSize;i++) {
        int c = min(f0,f1) + cost[i];
        f0 = f1;
        f1 = c;
    }
    return min(f1,f0);
}