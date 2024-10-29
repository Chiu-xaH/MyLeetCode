/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    var t = [];
    arr.forEach(
        (item,index) => t[index] = fn(item,index)
    );
    return t;
};