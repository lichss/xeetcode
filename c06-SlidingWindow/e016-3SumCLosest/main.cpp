#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int minDiff = __INT_MAX__;
        int closestSum = 0;

        for(int i=0;i<nums.size();i++){
            int left = i+1;
            int rigt = nums.size()-1;
            while(left<rigt){
                int sum = nums[left] + nums[rigt] + nums[i];
                int diff = sum - target;
                // minDiff = std::min(minDiff,std::abs(diff));
                if( std::abs(diff) < minDiff){
                    closestSum = sum;
                    minDiff = std::abs(diff);
                }

                if(diff > 0)
                    rigt--;
                if(diff < 0)
                    left++;
                else
                    return sum;
            }
        }

        return closestSum;
            
    }
};

int main(){

    std::cout << "returned\n";

    return 0; 
}