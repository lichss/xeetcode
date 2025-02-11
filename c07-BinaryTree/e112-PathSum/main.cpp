#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {
void recur(TreeNode* node,int targetSum,int sum,bool& flag) {
    if(!node) return;
    sum += node->val;
    if(sum == targetSum && !node->left && !node->right) 
        flag = true;
    recur(node->left,targetSum,sum,flag);
    recur(node->right,targetSum,sum,flag);

    return;
}

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool falg = false;
        recur(root,targetSum,0,falg);
        return falg;
        
    }
};

int main() {
    return 0;
}