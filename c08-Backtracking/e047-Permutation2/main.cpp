#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"
using std::vector;



class Solution {
std::vector<vector<int>> combs;
std::vector<int> path;
std::vector<int> used;
void backtrack(std::vector<int>& nums){

    std::vector<int> layer;
    for(int i=0;i<nums.size();i++){
       
        if(!used[i]  && (std::find(layer.begin(),layer.end(),nums[i]) == layer.end())){
            path.push_back(nums[i]);
            layer.push_back(nums[i]);
            used[i] = true;
            if(path.size() == nums.size())
                combs.push_back(path);
            else
                backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }

    return;
}


public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       used.resize(nums.size(),false); 
       backtrack(nums);
       return combs;
    }
};


int main() {

    return 0;
}