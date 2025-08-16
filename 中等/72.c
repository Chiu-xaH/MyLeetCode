int min(int a,int b,int c) {
    int firstMin;
    if(a < b) {
        firstMin = a;
    } else {
        firstMin = b;
    }
    if(firstMin < c) {
        return firstMin;
    } else {
        return c;
    }
}

int minDistance(char* word1, char* word2) {
    int len1 = 0,len2 = 0;
    while(word1[len1] != '\0') {
        len1++;
    }
    while(word2[len2] != '\0') {
        len2++;
    }
    int dp[len1+1][len2+1];
    for(int i = 0;i <= len1;i++) {
        dp[i][0] = i;
    }
    for(int i = 0;i <= len2;i++) {
        dp[0][i] = i;
    }
    for(int i = 1;i <= len1;i++) {
        for(int j = 1;j <= len2;j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1;
            }
        }
    }
    return dp[len1][len2];
}