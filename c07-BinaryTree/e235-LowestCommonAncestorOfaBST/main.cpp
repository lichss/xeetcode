#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"

class Solution {
    int min,max;
private:
    TreeNode* recurPreorder(TreeNode* node){
        if(!node)   return nullptr;
        if(node->val >= min && node->val <= max)
            return node;
        TreeNode* inLeft = nullptr;
        if( inLeft = recurPreorder(node->left))
            return inLeft;
        return recurPreorder(node->right);

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // int min,max;
        min = p->val < q->val ? p->val : q->val;
        max = p->val > q->val ? p->val : q->val;

        return recurPreorder(root);


    }
};

int main() {

    return 0;
}