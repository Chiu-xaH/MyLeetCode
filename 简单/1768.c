char* mergeAlternately(char* word1, char* word2) {
    // 计算长度
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int totalLen = len1 + len2;
    char* result = (char*)malloc(totalLen + 1);
   
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    while(index1 < len1 && index2 < len2) {
        result[index++] = word1[index1++];
        result[index++] = word2[index2++];
    }
    while(index1 < len1) {
        result[index++] = word1[index1++];
    }
    while(index2 < len2) {
        result[index++] = word2[index2++];
    }
    result[index] = '\0';
    return result;
}