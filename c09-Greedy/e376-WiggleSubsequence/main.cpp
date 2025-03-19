#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }else if(nums.size() == 1){
            return 1;
        }else if(nums.size() == 2){
            return (nums[0] == nums[1]) ? 1:2;
        }

        int grd = (nums[0] == nums[1]) ? 1:2;
        int d=0;
        bool prevDiff,curDiff;
        int startIndex = 1;
        int m=1;
        for( m=1;m<nums.size() && nums[m]==nums[m-1];){
            m++;
        }
        prevDiff = (nums[1]-nums[0] > 0);
        for(int i=startIndex+m;i<nums.size();i++){
            d = nums[i] - nums[i-1];
            if(d == 0){
                continue;
            }
            curDiff = (d > 0);
            if( curDiff != prevDiff){ /*摇摆 */
                grd++;
                prevDiff = curDiff;
            }
        }
        return grd;
    }
};




int main(){


    return 0;
}
