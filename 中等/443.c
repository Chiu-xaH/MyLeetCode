// 获取数字有几位数
int getCount(int num) {
    if (num == 0) return 1;
    int count = 0;
    // 处理负数
    if (num < 0) num = -num;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}
// 把数字写入chars中，从write位置开始，返回写了几位
int writeNumber(char* chars, int write, int num) {
    char temp[10];
    int len = 0;
    do {
        temp[len++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);
    for (int i = len - 1; i >= 0; i--) {
        chars[write++] = temp[i];
    }
    return len;
}

int compress(char* chars, int charsSize) {
    int write = 0;
    char ch = chars[0];
    int ptr = 1;
    int count = 1;
    while(ptr != charsSize) {
        char current = chars[ptr];
        if(current != ch) {
            // 上一个ch结束
            // 写入字符
            chars[write++] = ch;
            // 写入计数（如果大于1）
            if (count > 1) {
                write += writeNumber(chars, write, count);
            }
            // 重置
            ch = current;
            count = 1;
        } else {
            count++;
        }
        ptr++;
    }
    // 处理最后一组字符
    chars[write++] = ch;
    if (count > 1) {
        write += writeNumber(chars, write, count);
    }
    return write;
}