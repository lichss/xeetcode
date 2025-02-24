#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"
/* 南无！ 说是Middle Level ， 实际简单！！ */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode* node = root;
        
        while(node){
            if(val > node->val)
                if(node->right){
                    node = node->right;
                }else{
                    node->right = new TreeNode(val);
                    return root;
                }
            else{/* val < node.val*/
                if(node->left){
                    node = node->left;
                }else{
                    node->left = new TreeNode(val);
                    return root;
                }
            }
        }
        return root;
    }
};

int main() {

    return 0;
}