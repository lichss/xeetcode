#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "../leetcodeStruct/treenode.h"


// Definition for a binary tree node.

class Solution {

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if(preorder.empty())
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootIndex = findElementIndex(inorder, preorder[0]);
        std::vector<int> inorderLeftTrees(inorder.begin(), inorder.begin() + rootIndex);
        std::vector<int> inorderRightTrees(inorder.begin() + rootIndex + 1, inorder.end());
        std::vector<int> preorderLeftTrees(preorder.begin() + 1, preorder.begin() + 1 + inorderLeftTrees.size());
        std::vector<int> preorderRightTrees(preorder.begin() + 1 + inorderLeftTrees.size(), preorder.end());
        root->left = buildTree(preorderLeftTrees, inorderLeftTrees);
        root->right = buildTree(preorderRightTrees, inorderRightTrees);
        return root;
                    
    }
    static int findElementIndex(const std::vector<int>& vec, int target) {
        auto it = std::find(vec.begin(), vec.end(), target);
        if (it != vec.end()) {
            return std::distance(vec.begin(), it);
        }
        return -1; // Return -1 if the element is not found
    }
    
};


int main(){

    std::vector<int> inorder = {9,3,15,20,7};
    std::cout << Solution:: findElementIndex(inorder, 20) << std::endl;

    return 0;
}