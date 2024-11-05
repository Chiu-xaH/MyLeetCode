int scoreOfString(char* s) {
    int i = 1;
    int res = 0;
    while(s[i] != '\0') {
        res += fabs(s[i]-s[i-1]);
        i++;
    }
    return res;
}