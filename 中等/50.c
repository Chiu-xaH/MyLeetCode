double myPow(double x, int n) {
    double result = 1.0;
    if(x == 1 || n == 0) {
        return 1;
    }
    long nn = n;  // 使用 long 来避免 n 可能为负的情况导致的溢出
    if (nn < 0) {
        x = 1 / x;
        nn = -nn;
    }
   // for(int i = 0;i < nn;i++) {
     //   if(n > 0) result *= x;
       // else result *= 1/x;
    //}
    while (nn > 0) {
        if (nn % 2 == 1) {  // 如果 nn 是奇数
            result *= x;
        }
        x *= x;  // 平方 x
        nn /= 2; // nn 减半
    }
    return result;
}
//快速幂