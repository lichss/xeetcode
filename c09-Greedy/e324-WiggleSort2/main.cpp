#include <iostream>
#include <vector>
#include <algorithm>

/*
    笨贪心 有点子贪不出来
*/
class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        auto ordered = nums;
        std::sort(ordered.begin(),ordered.end());

        int l=0,r = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0)
                nums[i] = ordered[l++];
            else
                nums[i] = ordered[r--];

        }

        return;
    }
};

int main(){


    return 0;
}
