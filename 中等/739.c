/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = temperaturesSize - 1; i >= 0; i--) {
        // 把栈顶比当前温度小或相等的都弹出
        while (top >= 0 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }

        if (top >= 0) {
            result[i] = stack[top] - i;
        } else {
            result[i] = 0; // 后面没有比它高的温度
        }

        // 把当前索引入栈
        stack[++top] = i;
    }

    free(stack);
    *returnSize = temperaturesSize;
    return result;   
}