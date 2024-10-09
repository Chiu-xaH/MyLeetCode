long long tribonacci(int n){
    long long tn = 0,tn1 = 1,tn2 = 1;
    long long tn3 = tn + tn1 + tn2;
    for(int i = 0;i < n;i++) {
        tn3 = tn + tn1 + tn2;
        tn = tn1;
        tn1 = tn2;
        tn2 = tn3;
    }
    return tn;
}