#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"


class Solution {
    int findMaxElemIndex(const std::vector<int>& nums) {
        auto maxIt = std::max_element(nums.begin(), nums.end());
        return std::distance(nums.begin(), maxIt);
    }
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int maxIndex = findMaxElemIndex(nums);
        TreeNode* newRoot = new TreeNode(nums[maxIndex]);
        std::vector<int> vecLeftSubTree(nums.begin(), nums.begin() + maxIndex); /*我觉得这个地方可能会导致一个bug  然而实际上不会，因为这个地方的maxIndex==0的时候，会构建空vector */
        std::vector<int> vecRightSubTree(nums.begin() + maxIndex + 1, nums.end());
        newRoot->left = constructMaximumBinaryTree(vecLeftSubTree);
        newRoot->right = constructMaximumBinaryTree(vecRightSubTree);
        return newRoot;

    }
};


int main() {

    return 0;
}