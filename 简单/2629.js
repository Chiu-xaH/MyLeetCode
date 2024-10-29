/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
	return function(x) {
        var len = functions.length
        var result = x
        for(var i = len-1;i >= 0;i--) {
            result = functions[i](result)
        }
        return result
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */