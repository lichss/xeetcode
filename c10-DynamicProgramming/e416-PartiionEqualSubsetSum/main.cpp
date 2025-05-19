#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int> (nums.size()));

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            dp[0][i] = nums[0];
            dp[i][0] = 0;
        }

        if(sum % 2 == 1)
            return false;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<sum/2 && j<nums.size();i++){
                if(j - nums[i] >= 0)
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i] );
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[sum/2][sum/2] == sum/2;

    }
};




int main(){


    return 0;
}
