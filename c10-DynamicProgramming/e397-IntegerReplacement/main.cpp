#include <iostream>
#include <vector>
#include <algorithm>

/*
神人题目 倒数第二个测试用例是 n = 2147483647;
不让用dp直说嗷

*/
#if 0
class Solution {
public:
    int integerReplacement(int n) {
        if(n<=2)
            return n;
        std::vector<int> dp(n+1) ;
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3;i<n;i++){
            if(i%2 == 0){
                dp[i] = dp[i/2]+1;
            }else{
                dp[i] = std::min(dp[i-1]+1,dp[(i+1) / 2]+2);
            }
        }
        return dp[n];
    }
};
#endif
class Solution{
public:
    int integerReplacement(int n) {
        if(n==1)
            return 0;

        if(n%2 == 0){
            return integerReplacement(n/2) + 1;
        }else{
            return std::min(integerReplacement(n-1)+1,integerReplacement((n+1) / 2)+2);
        }

    }
};


int main(){


    return 0;
}
