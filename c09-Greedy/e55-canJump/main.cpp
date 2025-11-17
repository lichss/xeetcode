#include <iostream>
#include <vector>

#if 0
/* 我自己想的这个方法有点奔了。
 * 每一次遇到0都需要向后回溯。虽然不至于是O(n!)复杂度，但还是慢了不少 
 */
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        if(n == 1 )
            return true;
        if(!nums[0])
            return false;

        for(int i=0;i<n-1;){
            if(nums[i] + i>= n-1)
                return true;
            if(nums[i]){
                ++i;
                continue;
            }

            int j=i;
            for(int k = 0;;){
                if(nums[j] > k)
                    break;                
                else if( j==0)
                    return false;
                
                else{
                    k++;j--;
                }
            }
            ++i;
        }
        return true;
    }
};

#endif
#if 1
/*他山之玉 又好又好*/
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int step_remain=0;
        for(int i=0;i<nums.size()-1;){
            if(nums[i]>step_remain)
                step_remain = nums[i];
            
            else if(step_remain == 0 && nums[i]==0)
                return false;
            
            step_remain--;
        }
        return true;

    }
};
#endif


int main(){



    return 0;
}