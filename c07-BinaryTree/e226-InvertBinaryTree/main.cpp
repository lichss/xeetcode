#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        int curLevel_n=1, nextLevel_n=0;
        std::queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* node;
        while(!qu.empty()){
            node = qu.front();
            qu.pop();
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
            std::swap(node->left, node->right);

        }
        return root;
    }
};

int main() {
    return 0;
}