#include <iostream>
#include <vector>


class Solution {
public:
    int jump(std::vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int pr = nums[0];
        int sub=0;
        int j=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>sub){
                sub = nums[i];
            }
            if(pr==0){
                pr = sub;
                j++;
            }
            pr--;
            sub--;
        }
        return ++j;

    }
};
int main(){


    return 0;
}