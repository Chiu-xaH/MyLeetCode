/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 1000
typedef int Elemtype;
typedef struct {
    int top;
    Elemtype data[MAXSIZE];
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
}

bool Push(Stack *S, Elemtype E) {
    if(S->top == MAXSIZE - 1) {
        return false;
    }
    S->data[++S->top] = E;
    return true;
}

bool Pop(Stack *S, Elemtype *E) {
    if(S->top == -1) {
        return false;
    }
    *E = S->data[S->top--];
    return true;
}

int Length(Stack S) {
    return S.top + 1;
}

// 求绝对值
int a(int n) {
    return n >= 0 ? n : -n;
}


int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    // 思路 进栈两个，然后判断符号相异则保留绝对值最大的那个，符号相同则继续进栈
    Stack S;
    InitStack(&S);

    for(int i = 0; i < asteroidsSize; ++i) {
        int curr = asteroids[i];
        bool alive = true;

        // 当前小行星向左，栈顶小行星向右，可能发生碰撞
        while(alive == true && curr < 0 && S.top != -1 && S.data[S.top] > 0) {
            int top = S.data[S.top];
            if(a(top) < a(curr)) {
                // 栈顶被撞爆，继续比较下一个
                int temp;
                Pop(&S, &temp);
            } else if(a(top) == a(curr)) {
                // 相等则都爆炸
                int temp;
                Pop(&S, &temp);
                alive = false;
            } else {
                // 栈顶大，当前被撞爆
                alive = false;
            }
        }

        if(alive == true) {
            Push(&S, curr);
        }
    }

    // 转换为结果数组
    *returnSize = Length(S);
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = *returnSize - 1; i >= 0; --i) {
        int temp;
        Pop(&S, &temp);
        result[i] = temp;
    }

    return result;
}