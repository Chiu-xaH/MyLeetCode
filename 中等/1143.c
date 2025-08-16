int max(int a,int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = 0,len2 = 0;
    while(text1[len1] != '\0') {
        len1++;
    }
    while(text2[len2] != '\0') {
        len2++;
    }
    int dp[len1+1][len2+1];
    for(int i = 0;i <= len1;i++) {
        dp[i][0] = 0;
    }
    for(int i = 0;i <= len2;i++) {
        dp[0][i] = 0;
    }
    for(int i = 1;i <= len1;i++) {
        for(int j = 1;j <= len2;j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}