//引入队列
#define MAXVEX 100

#define AIR '.'
#define WALL ','
#define VISITED '-'

typedef struct {
    int x;
    int y;
    int step;
} Pos;

typedef Pos ElemType;
typedef struct {
    ElemType data[MAXVEX];
    int front;
    int rear;
} Queue;

void Init(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

bool Add(Queue *Q,ElemType E) {
    if ((Q->rear + 1) % MAXVEX == Q->front) {
        return false;
    }	
	Q->data[Q->rear] = E;	
    Q->rear++;		
	Q->rear = Q->rear % MAXVEX;
    return true;
}

bool DeAdd(Queue *Q,ElemType *E) {
    if(Q->front == Q->rear) {
        return false;
    }
    *E = Q->data[Q->front];
    Q->front++;
    Q->front = Q->front % MAXVEX;
    return true;
}

int Length(Queue *Q) {
    if(Q->front == Q->rear) {
        return 0;
    }
    int count = 0;
    int i = Q->front;
    while(i != Q->rear) {
        count++;
        i++;
        i = i % MAXVEX;
    }
    return count;
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    // 思路 使用BFS从entrance开始，对周边AIR访问，直到找到最近的出口
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 上下左右方向
    Queue Q;
    Init(&Q);

    int startX = entrance[0];
    int startY = entrance[1];

    maze[startX][startY] = VISITED; // 标记入口已访问

    Add(&Q, (Pos){startX, startY, 0});
    while (Q.front != Q.rear) {
        Pos cur;
        DeAdd(&Q, &cur);

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dir[d][0];
            int ny = cur.y + dir[d][1];

            // 跳过墙壁
            if (nx < 0 || ny < 0 || nx >= mazeSize || ny >= mazeColSize[0]) continue;
            if (maze[nx][ny] != AIR) continue;

            // 是出口
            if (nx == 0 || ny == 0 || nx == mazeSize - 1 || ny == mazeColSize[0] - 1) {
                return cur.step + 1;
            }

            // 标记已访问
            maze[nx][ny] = VISITED;
            Add(&Q, (Pos){nx, ny, cur.step + 1});
        }
    }

    return -1; // 无法到达出口

}