bool isYuanYin(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
bool getCount(char ch) {
    if(isYuanYin(ch)) {
        return 1;
    } else {
        return 0;
    }
}
int getEndPtr(int start,int k) {
    return start + k - 1;
}

int maxVowels(char* s, int k) {
    int startPtr = 0;
    int endPtr = getEndPtr(startPtr,k);
    int totalCount = 0;
    for(int i = startPtr;i <= endPtr;i++) {
        totalCount += getCount(s[i]);
    }
    int maxCount = totalCount;
    while(s[endPtr + 1] != '\0') {
        totalCount = totalCount - getCount(s[startPtr]) + getCount(s[endPtr + 1]);
        if(totalCount > maxCount) {
            maxCount = totalCount;
        }
        startPtr++;
        endPtr++;
    }
    return maxCount;
}