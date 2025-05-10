#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        
        
        std::sort(nums.begin(),nums.end());
    
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n%2 ==0 ){
            return nums[n/2 -1];
        }        
        return nums[n/2 ];
    }
};

int main(){


    return 0;
}
