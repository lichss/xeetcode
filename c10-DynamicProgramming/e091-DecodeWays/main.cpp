#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // 空字符串有1种解码方式
        dp[1] = 1;   // 第一个字符不是'0'，所以有1种方式
        
        for (int i = 2; i <= n; ++i) {
            // 检查单数字解码
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // 检查双数字解码
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};


int main(){


    return 0;
}
