class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[s.size()][s.size()];// dp[i][j]表示区间范围[i,j](左闭右闭)的子串是否是回文子串
        for(int i = 0;i < s.size();i++) {
            for(int j = 0;j < s.size();j++) {
                dp[i][j] = false;
            }
        }

        string maxLenStr = s.substr(0, 1); // 至少有一个字符
        int maxLen = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) { 
                    if (j - i <= 1) { // 一个字符或者两个相同字符 回文串
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 判断两端是否也是回文串
                        dp[i][j] = true;
                    }
                }
                // 如果是回文子串并且更长，更新答案
                if (dp[i][j] && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    maxLenStr = s.substr(i, maxLen);
                }
            }
        }
        return maxLenStr;
    }
};

