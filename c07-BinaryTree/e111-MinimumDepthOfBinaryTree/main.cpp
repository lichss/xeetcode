#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        int curLevel_n=1, nextLevel_n=0;

        std::queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* node;
        while(!qu.empty()){
            node = qu.front();
            qu.pop();
            if(!node->left && !node->right) 
                return depth+1;
                
            if(node->left != nullptr) {
                qu.push(node->left);
                nextLevel_n++;
            }
            if(node->right != nullptr) {
                qu.push(node->right);
                nextLevel_n++;
            }

            curLevel_n--;
            if(!curLevel_n){
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
                depth++;
            }
        }
        return depth;
    }
};

int main() {
    return 0;
}