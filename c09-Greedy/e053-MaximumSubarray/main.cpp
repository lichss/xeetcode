#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        
        int cur_sum = nums[0];
        int acm_sum = INT_MIN;

        for(int i=1;i<nums.size();i++){
            cur_sum += nums[i];
            if(cur_sum > acm_sum){
                acm_sum = cur_sum;
            }
            if(cur_sum < 0){
                cur_sum = 0;
            }

        }

        acm_sum = std::max(acm_sum,cur_sum);
        return acm_sum;

    }
};
    



int main(){

    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    return 0;
}
