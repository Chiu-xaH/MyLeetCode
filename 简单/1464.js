var maxProduct = function(nums) {
    let max = 0;
    let second = 0;
    for(let i=0; i<nums.length; i++) {
        if(nums[i] > max){
            second = max;
            max = nums[i];
        }else if(nums[i] > second) {
            second = nums[i];
        }
    }
    return (max-1)*(second-1);
};