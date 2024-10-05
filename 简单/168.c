void reverse(char *str,int size) {
    int left = 0,right = size-1;
    while(left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

char* convertToTitle(int columnNumber) {
    char*  str = (char*)malloc(sizeof(char) * 10);
    int num = columnNumber;
    int i = 0;
    while(num != 0) {
        num--;
        char ch = 'A'+ num % 26;
        str[i] = ch;
        i++;
        num = num / 26;
    }
    str[i] = '\0';
    reverse(str,i);
    return str;
}