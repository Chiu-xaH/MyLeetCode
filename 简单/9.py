class Solution:
    def isPalindrome(self, x: int) -> bool:
        strs = str(x)
        reversed = strs[::-1]
        if(reversed == strs) :
            return True
        else : 
            return False