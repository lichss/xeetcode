#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
/*
 * 小骚题 写着真费劲
 * 或许一开始用绝对值排序没这么费劲了
 * 
*/
class Solution {
public:
    int largestSumAfterKNegations(std::vector<int> nums, int k) {
        std::sort(nums.begin(),nums.end());
        auto decide = [](std::vector<int>& nums,int i){
            if(nums[i]>0)
                if(i>0 && (nums[i-1] < nums[i]))
                    return i-1;
            return i;
        };

        for(int i=0;i<nums.size() && k;i++){
            if(nums[i]>=0){
                if(k%2)
                    nums[decide(nums,i)] *= -1;
                break;
            }

            nums[i] *= -1;
            k--; 
            if(i==nums.size()-1){
                if(k%2)
                    nums[i] *= -1;
                break;
            }
        }
        return std::accumulate(nums.begin(),nums.end(),0); 
    }
};





int main(){

    int a=2;
    a++;
    int c=a+1;
    Solution s;
    s.largestSumAfterKNegations(std::vector<int> {-1,3,-5,9,1,-5,-5,},8);

    return 0;
}
