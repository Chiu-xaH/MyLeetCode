/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(nums.length == 0) {
        return init
    }

    return reduce(nums.slice(1),fn,fn(init,nums[0]))
};