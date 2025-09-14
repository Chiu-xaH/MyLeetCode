int max(int i,int j) {
    if(i > j) {
        return i;
    } else {
        return j;
    }
}

int jump(int* nums, int numsSize) {
    // 当前能跳到的最远位置
    int maxVal = 0;
    // 当前这一步的“边界”
    int end = 0;
    int step = 0;
    // 到最后一个位置不用再跳
    for(int i = 0;i < numsSize-1;i++) {
        // 能跳到最后
        if(end == numsSize-1) {
            return step;
        }
        // 当前下标 i 能到达
        if(maxVal >= i) {
            // 更新最远位置
            maxVal = max(maxVal,i + nums[i]);
            if(i == end) {
                // 必须要跳一次才能继续前进
                step++;
                // 更新边界,下一跳能到达的新边界
                end = maxVal;
            }
        }
    }
    return step;
}