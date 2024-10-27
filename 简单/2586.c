bool isYuanYin(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int vowelStrings(char** words, int wordsSize, int left, int right) {
    int count = 0;
    for(int i = left;i <= right;i++) {
        int len = 0;
        while(words[i][len] != '\0') {
            len++;
        }
        if(isYuanYin(words[i][0]) && isYuanYin(words[i][len-1])) {
            count++;
        }
    }
    return count;
}