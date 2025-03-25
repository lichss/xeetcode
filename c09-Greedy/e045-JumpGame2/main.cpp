#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
public:
    int jump(std::vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int stp = nums[0];
        int hold=0;
        int change = 0;
        for(int i=0;i<nums.size()-1;i++){
            hold = std::max(hold,nums[i]);

            if(!stp){
                change++;
                stp = hold;
            }
            stp--;
            hold--;
        }

        return change+1;
    }
};



int main(){


    return 0;
}
