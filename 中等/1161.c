/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXSIZE 10000

typedef struct TreeNode* Tree;
//层序遍历
typedef struct {
    Tree data[MAXSIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = 0;////<--
    Q->rear = 0;//////-->
}

int Add(Queue *Q,Tree E) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return 0;
    }	
	Q->data[Q->rear] = E;	
    Q->rear++;		
	Q->rear = Q->rear % MAXSIZE;
    return 1;
}

int DeAdd(Queue *Q,Tree *E) {
    if(Q->front == Q->rear) {
        return 0;
    }
    *E = Q->data[Q->front];
    Q->front++;
    Q->front = Q->front % MAXSIZE;
    return 1;
}
//通用公式
int Length(Queue Q) {
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
//队列空
int isEmpty(Queue Q) {
    if(Q.front == Q.rear) {
        return 1;
    } else {
        return 0;
    }
}
//层序遍历
int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;

    Queue Q;
    InitQueue(&Q);
    Add(&Q, root);

    int maxSum = root->val;
    int maxLevel = 1;
    int currentLevel = 1;

    while (!isEmpty(Q)) {
        int levelSize = Length(Q);  // 当前层有多少节点
        int levelSum = 0;

        for (int i = 0; i < levelSize; i++) {
            Tree node;
            DeAdd(&Q, &node);
            levelSum += node->val;

            if (node->left) Add(&Q, node->left);
            if (node->right) Add(&Q, node->right);
        }

        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = currentLevel;
        }

        currentLevel++;
    }

    return maxLevel;
}
