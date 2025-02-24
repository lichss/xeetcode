#include <iostream>
#include <vector>
#include <queue>
#include "../leetcodeStruct/treenode.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        std::vector<int> vec;
        TreeNode* node = root;

        std::queue<TreeNode*> qu;  
        qu.push(node);

        int nextLevel_n = 0;
        int curLevel_n = 1;

        while(!qu.empty()){
            node = qu.front();
            qu.pop();
            
            if(node->left){
                qu.push(node->left);
                nextLevel_n++;
            }
            if(node->right){
                qu.push(node->right);
                nextLevel_n++;
            }
            curLevel_n--;

            if(!curLevel_n){
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
                vec.push_back(node->val);
            }
        }
        return vec;

    }
};

int main(){
    std::cout<<"sasda\n";




    return 0;
}