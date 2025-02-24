#include <iostream>
#include <vector>
#include <queue>
#include "../leetcodeStruct/treenode.h"
#include <algorithm>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> vec;
        TreeNode* node = root;
        std::queue<TreeNode*> qu;

        int nextLevel_n = 0;
        int curLevel_n = 1;        
        auto layer = new std::vector<int>;

        if(node)
            qu.push(node);
        
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
            layer->push_back(node->val);
            
            curLevel_n--;
            if(!curLevel_n){
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
                vec.push_back(*layer);
                layer->clear();
            }
        }
        // delete layer;
        std::reverse(vec.begin(),vec.end());
        return vec;

        
    }
};


int main(){
    




    return 0;
}