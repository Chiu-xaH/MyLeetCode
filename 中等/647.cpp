class Solution {
public:
    int countSubstrings(string s) {
        bool dp[s.size()][s.size()];// dp[i][j]表示区间范围[i,j](左闭右闭)的子串是否是回文子串
        for(int i = 0;i < s.size();i++) {
            for(int j = 0;j < s.size();j++) {
                dp[i][j] = false;
            }
        }
        
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) { 
                    if (j - i <= 1) { // 一个字符或者两个相同字符 回文串
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 判断两端是否也是回文串
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};