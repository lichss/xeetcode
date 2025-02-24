#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"

class Solution {
private:
    std::vector<int> vec;
    int minDiff = INT_MAX;
    TreeNode* pre = nullptr;
    void inoderTraversal(TreeNode* node){
        if(!node)   return;

        inoderTraversal(node->left);
        if(pre)
            minDiff = node->val - pre->val < minDiff ? node->val - pre->val : minDiff;

        pre = node;
        inoderTraversal(node->right);

        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {

        inoderTraversal(root);
        return minDiff;

    }
};

int main() {

    return 0;
}