char* restoreString(char* s, int* indices, int indicesSize) {
    char* str = (char*)malloc((indicesSize + 1) * sizeof(char));
    for(int i = 0;i <= indicesSize;i++) {
        str[i] = '\0';
    }
    for(int i = 0;i < indicesSize;i++) {
        str[indices[i]] = s[i];
    }
    return str;
}