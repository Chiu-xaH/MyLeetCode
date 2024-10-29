/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var t = [];
    arr.forEach(
        (item,index) => {
            if(fn(item,index)) t.push(item)
        }
    );
    return t;
};