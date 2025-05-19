#include <iostream>
#include <vector>
#include <algorithm>
/*
    好久没做题了, 先做点简单题回复一下手感.

*/
class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        
        std::sort(nums.begin(),nums.end());                
        int sum=0;
        for(int i=0;i<nums.size();i+=2){
            sum += nums[i];

        }

        return sum;
    }
};

int main(){


    return 0;
}
