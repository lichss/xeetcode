#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        std::queue<TreeNode*> qu;
        qu.push(root);
        int count = 1;
        int curLevel_n=1, nextLevel_n=0;
        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            if(node->left){
                qu.push(node->left);
                nextLevel_n++;
                count++;
            }
            if(node->right){
                qu.push(node->right);
                nextLevel_n++;
                count++;
            }
            if(--curLevel_n == 0){
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
            }
        }
        return count;  
    }
};

int main() {
    return 0;
}