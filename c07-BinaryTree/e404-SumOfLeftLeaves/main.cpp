#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {
void recur(TreeNode* node,bool from_left,int& sum){
    if(!node)
        return;
    if(from_left && !node->left && !node->right)
        sum += node->val;
    recur(node->left,1,sum);
    recur(node->right,0,sum);

    return;
}
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        recur(root,0,sum);
        return sum;
    }
};

int main() {
    return 0;
}