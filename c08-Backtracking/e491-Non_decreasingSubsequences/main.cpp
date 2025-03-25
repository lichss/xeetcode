#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

using std::vector;

class Solution {
std::vector<int> path;
std::vector<std::vector<int>> combs;

void backtrack(std::vector<int>& nums, int starIndex){
    int newNum;
    std::vector<int> layer = {};

    for(int i=starIndex;i<nums.size();i++){
        
        if( std::find(layer.begin(),layer.end(),nums[i]) == layer.end()){
            layer.push_back(nums[i]);
            newNum = nums[i];

            if(path.empty() || newNum >= path.back()){
                path.push_back(newNum);
                if(path.size()>1)
                    combs.push_back(path);
                backtrack(nums,i+1);
                path.pop_back();

            }
        }
    }
    return;
}

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums,0);
        return combs;
    }
};

int main() {

    return 0;
}