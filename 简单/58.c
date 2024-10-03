int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int ptr = len-1;
    int count = 0;
    while(ptr >= 0 && s[ptr] == ' ') {
        ptr--;
    }
    while(ptr >= 0 && s[ptr] != ' ') {
        ptr--;
        count++;
    }
    return count;
}