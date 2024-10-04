//队列
const int QUEUE1 = 1,QUEUE2 = 2;

typedef struct {
    int data[100];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

void Add(Queue *Q,int E) {
    if ((Q->rear + 1) % 100 == Q->front) {
        return;
    }	
	Q->data[Q->rear] = E;	
    Q->rear++;		
	Q->rear = Q->rear % 100;
}

void DeAdd(Queue *Q,int *E) {
    if(Q->front == Q->rear) {
        return;
    }
    *E = Q->data[Q->front];
    Q->front++;
    Q->front = Q->front % 100;
}

int Length(Queue Q) {
    return (Q.rear-Q.front+100)%100;
}

bool GetQueue(Queue Q) {
    if(Q.front == Q.rear) {
        return 0;
    }
    int i = Q.front;
    while(i != Q.rear) {
        printf("%d ",Q.data[i]);
        i++;
        i = i % 100;
    }
    printf("\n");
    return 1;
}

bool isFull(Queue Q) {
    if((Q.rear+1)%100 == Q.front) {
        return 1;
    } else {
        return 0;
    }
}

typedef struct {
    Queue Q1,Q2;
    int mainContainer;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    InitQueue(&stack->Q1);
    InitQueue(&stack->Q2);
    stack->mainContainer = QUEUE1;  // 初始化主容器为Q1
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    Queue *Q = (obj->mainContainer == QUEUE1) ? &obj->Q1 : &obj->Q2;
    Add(Q, x);
}

int myStackPop(MyStack* obj) {
     Queue *Q = (obj->mainContainer == QUEUE1) ? &obj->Q1 : &obj->Q2;
    Queue *otherQ = (obj->mainContainer == QUEUE1) ? &obj->Q2 : &obj->Q1;

    while (Length(*Q) > 1) {
        int E;
        DeAdd(Q, &E);
        Add(otherQ, E);
    }
    
    int poppedValue;
    DeAdd(Q, &poppedValue);
    
    // 交换主容器
    obj->mainContainer = (obj->mainContainer == QUEUE1) ? QUEUE2 : QUEUE1;
    return poppedValue;
}

int myStackTop(MyStack* obj) {
    Queue *Q = (obj->mainContainer == QUEUE1) ? &obj->Q1 : &obj->Q2;
    if (Length(*Q) == 0) {
        return -1;  // 栈为空
    }

    // 返回栈顶元素（不出栈）
    int topValue;
    int ptr = Q->rear - 1;
    return Q->data[ptr];
}

bool myStackEmpty(MyStack* obj) {
    Queue *Q = (obj->mainContainer == QUEUE1) ? &obj->Q1 : &obj->Q2;
    return Length(*Q) == 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/