/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe:(n)=> {
            if(n !== val) throw 'Not Equal'
            else return true
        },
        notToBe:(n)=> {
            if(n === val) throw 'Equal'
            else return true
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */