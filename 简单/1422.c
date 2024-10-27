int length(char *s) {
    int len = 0;
    while(s[len] != '\0') {
        len++;
    }
    return len;
}

int maxScore(char* s) {
    int len = length(s);
    int maxScore = 0;
    for(int i = 0;i < len-1;i++) {
        int score = 0;
        int left = 0,right = len-1;
        int center = i;
        while(left <= i) {
            if(s[left] == '0') score++;
            left++;
        }
        while(right > i) {
            if(s[right] == '1') score++;
            right--;
        }
        if(score > maxScore) maxScore = score;
    }
    return maxScore;
}