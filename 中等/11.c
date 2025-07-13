int min(int a,int b) {
    if(a > b) {
        return b;
    } else {
        return a;
    }
}

int maxArea(int* height, int heightSize) {
    int left = 0,right = heightSize-1;
    int maxVol = 0;
    while(left <= right) {
        int leftHeight = height[left];
        int rightHeight = height[right];
        int width = right - left;
        int height = min(rightHeight,leftHeight);
        int volume = width * height;
        if(volume > maxVol) {
            maxVol = volume;
        }
        if(rightHeight > leftHeight) {
            left++;
        } else if(rightHeight < leftHeight) {
            right--;
        } else {
            left++;
            right--;
        }
    }
    return maxVol;
}