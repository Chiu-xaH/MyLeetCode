//返回值为1则互质
int gcd(int a,int b)
{
    int t;
    if(a<b)
    {
        t=a;a=b;b=t;
    }
    while(a%b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return b;
}

int getFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int getLastDigit(int num) {
    return num % 10;
}

int countBeautifulPairs(int* nums, int numsSize){
    int count = 0;
    for(int i = 0;i < numsSize;i++) {
        for(int j = i+1;j < numsSize;j++) {
            if(gcd(getFirstDigit(nums[i]),getLastDigit(nums[j])) == 1) {
                count++;
            }
        }
    }
    return count;
}