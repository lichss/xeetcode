#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
这里多说一句 copilot 太jb好用了。
递归构造的逻辑我晓得，但数组分割方式和数组查找元素的简单实现我都没写。全是copilot给的。
甚至这段注释的一部分也是copilot给的！！
总的来说，能很大程度提供生产力，但学习阶段是坏习惯
*/

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
int findIndex(const std::vector<int>& vec, int target) {
    auto it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    return -1; // Return -1 if the element is not found
}

public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if(postorder.empty())
        return nullptr;
    TreeNode* newRoot = new TreeNode(postorder.back());
    int rootIndexInInorder = findIndex(inorder, newRoot->val);
    std::vector<int> leftTreesInorder(inorder.begin(), inorder.begin() + rootIndexInInorder);
    std::vector<int> rightTreesInorder(inorder.begin() + rootIndexInInorder + 1, inorder.end());
    std::vector<int> leftTreesPostorder(postorder.begin(), postorder.begin() + rootIndexInInorder);
    std::vector<int> rightTreesPostorder(postorder.begin() + rootIndexInInorder, postorder.end() - 1);
    
    newRoot->left = buildTree(leftTreesInorder, leftTreesPostorder);
    newRoot->right = buildTree(rightTreesInorder, rightTreesPostorder);
    return newRoot;
        
    }
};

int findElementIndex(const std::vector<int>& vec, int target) {
    auto it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    return -1; // Return -1 if the element is not found
}

int main(){

    std::vector<int> inorder = {9,3,15,20,7};
    std::cout << findElementIndex(inorder, 20) << std::endl;

    return 0;
}