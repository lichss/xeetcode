#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        int curLevel_n=1, nextLevel_n=0;

        std::queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* node;
        while(!qu.empty()){
            node = qu.front();
            qu.pop();
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

class Solution_cur{

int recur_depth(TreeNode* node){
    if(!node) return 0;
    int left = recur_depth(node->left)+1;
    int right = recur_depth(node->right)+1;
    return std::max(left,right);
}


public:
    int maxDepth(TreeNode* root){

        return recur_depth(root);
    }

};


int main() {
    return 0;
}