bool isSubsequence(char* s, char* t) {
    int ptr1 = 0,ptr2 = 0;
    int count = 0;

    int len1 = 0;
    while(s[len1] != '\0') {
        len1++;
    }

    while(s[ptr1] != '\0' && t[ptr2] != '\0' && count != len1) {
        if(s[ptr1] == t[ptr2]) {
            count++;
            ptr1++;
            ptr2++;
        } else {
            ptr2++;
        }
    }
    if(count == len1) {
        return true;
    }
    return false;
}