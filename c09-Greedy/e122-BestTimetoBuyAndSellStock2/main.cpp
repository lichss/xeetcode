#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
public:
    int maxProfit(std::vector<int>& nums) {
        int hold = nums[0];
        int profit = 0;
        for(int i=0;i<nums.size();i++){
            int diff = nums[i] - hold;
            if(diff > 0){
                profit += diff;
                hold = nums[i];
            }else if(diff < 0){
                hold = nums[i];
            }
        }
        return profit;
    }
};



int main(){


    return 0;
}
