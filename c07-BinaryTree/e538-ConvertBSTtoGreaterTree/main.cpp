#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

class Solution {
private:
    int sum=0;
public:
    void recur(TreeNode* node){
        if(!node) return;
        recur(node->right);
        sum+=node->val;
        node->val = sum;
        recur(node->left);

        return;

    }

    TreeNode* convertBST(TreeNode* root) {
        recur(root);

        return root;
    }
};

int main() {

    return 0;
}