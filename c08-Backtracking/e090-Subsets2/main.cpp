#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

class Solution {
private:
std::vector<int> path;
std::vector<std::vector<int>> combs = {{},};
std::vector<int> nums;

void backtrack(int startIndex){

    int newNum=nums[0];
    for(int i=startIndex;i<nums.size();i++){

        if(i == startIndex || nums[i-1]!=nums[i]){
            newNum = nums[i];
            path.push_back(newNum);
            combs.push_back(path);
            backtrack(i+1);
            path.pop_back();        
        }
    }

    return;
}
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        this->nums = nums;
        std::sort(this->nums.begin(),this->nums.end());
        backtrack(0);
        return combs;
    }
};
    
int main() {

    return 0;
}