#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int stp = nums[0];
        int i=0;
        for(;i<nums.size() ;){
            if(!stp && !nums[i])
                break;
            stp = std::max(stp,nums[i]);
            stp--;
            i++;
        }  
        return i >= nums.size()-1;
    }
};



int main(){


    return 0;
}
