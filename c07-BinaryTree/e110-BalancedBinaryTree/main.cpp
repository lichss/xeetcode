#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {

int recur_depth(TreeNode* node,bool& balanced){
    if(!node) return 0;
    int left = recur_depth(node->left,balanced)+1;
    int right = recur_depth(node->right,balanced)+1;

    int diff = std::abs(left-right);
    if(diff>1) 
        balanced = false;

    return std::max(left,right);
}

public:
    bool isBalanced(TreeNode* root) {

        if(!root) return true;
        bool balanced = true;
        recur_depth(root,balanced);


        return balanced;
    }
};

int main() {
    return 0;
}