bool isYuanYin(char s) {
    return s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U' || s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

void swap(char* s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

char* reverseVowels(char* s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    // 双指针
    int left = 0,right = length-1;
    while(left <= right) {
        bool isLeft = isYuanYin(s[left]);
        bool isRight = isYuanYin(s[right]);
        if(!isLeft && isRight) {
            left++;
        } else if(isLeft && !isRight) {
            right--;
        } else if(!isLeft && !isRight) {
            left++;
            right--;
        } else if(isLeft && isRight) {
            // 交换
            swap(s,left,right);
            left++;
            right--;
        }
    }
    return s;
}