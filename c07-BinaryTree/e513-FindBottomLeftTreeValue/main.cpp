#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        std::queue<TreeNode*> qu;
      
        int most_left = 0;
        qu.push(root);
        int curLevel=1;
        TreeNode* node;
        while(!qu.empty()) {
            node = qu.front();
            qu.pop();
            
            most_left = node->val;
            if(node->right) qu.push(node->right);
            if(node->left) qu.push(node->left);

            if(--curLevel==0) {                
                curLevel = qu.size();

            }
        }
        return most_left;
    }
};

int main() {
    return 0;
}