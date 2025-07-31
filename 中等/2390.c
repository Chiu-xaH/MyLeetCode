#define MAXSIZE 100000

typedef char Elemtype;
typedef struct {
    int top;
    Elemtype data[MAXSIZE];
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
}

bool Push(Stack *S,Elemtype E) {
    if(S->top == MAXSIZE) {
        return false;
    }
    S->top++;
    S->data[S->top] = E;
    return true;
}

bool Pop(Stack *S) {
    if(S->top == -1) {
        return false;
    }
    S->top--;
    return true;
}


int Length(Stack S) {
    return S.top + 1;
}
bool isEmpty(Stack S) {
    return Length(S) == 0;
}


char* removeStars(char* s) {
    Stack S;
    InitStack(&S);
    int count = 0;
    while(s[count] != '\0') {
        if(s[count] == '*') {
            // 是星号，出栈
            Pop(&S);
        } else {
            // 是字符 继续
            Push(&S,s[count]);
        }
        count++;
    }
    // 遍历栈，返回新的字符串
    int len = Length(S);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = len - 1; i >= 0; i--) {
        result[i] = S.data[S.top];
        S.top--;
    }
    result[len] = '\0';
    return result;
}