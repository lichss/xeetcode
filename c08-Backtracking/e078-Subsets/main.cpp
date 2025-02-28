#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

using std::vector;

class Solution {

private:
    std::vector<int> path;
    std::vector<vector<int>> combs = {};
    std::vector<int> nums;

    void backtrack(int startIndex){

        

        int newNum;
        for(int i=startIndex;i<nums.size();i++){
            newNum = nums[i];
            path.push_back(newNum);
            backtrack(i+1);
            combs.push_back(path);
            path.pop_back();

        }

        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        backtrack(0);
        return combs;
    }
};

int main() {

    return 0;
}