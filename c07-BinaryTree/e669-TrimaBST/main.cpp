#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"


class Solution {
private:
    TreeNode* recur(TreeNode* node,int low,int high){
        if(!node)   return nullptr;
        if(node->val < low){
            return recur(node->right,low,high);
        }
        if(node->val > high){
            return recur(node->left,low,high);
        }
        node->left = recur(node->left,low,high);
        node->right = recur(node->right,low,high);
        
        
        return node;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = recur(root,low,high);

        return root;
    }
};
    


int main() {

    return 0;
}