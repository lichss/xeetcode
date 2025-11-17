#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::vector<int> dp_postive(nums.size());
        dp_postive[0] = nums[0];

        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            dp_postive[i] = std::max(dp_postive[i-1] * nums[i],nums[i]);
            
            max = std::max(max,dp[i]);
        }
        return max;
    }
};




int main(){


    return 0;
}
