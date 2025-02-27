#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

class Solution {
public:
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        

        int miden = nums.size()/2;
        auto newNode = new TreeNode(nums[miden]);
        newNode->left = sortedArrayToBST(std::vector<int> (nums.begin(), nums.begin() + miden));
        newNode->right = sortedArrayToBST(std::vector<int> (nums.begin() + miden + 1, nums.end()));
        return newNode;;
    }
};

int main() {


    return 0;
}