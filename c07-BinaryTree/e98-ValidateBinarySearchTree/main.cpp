#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"


// 保留一下最初的思路。错的 闹麻了
class Solution_wrong {
    bool recur_isValidBST(TreeNode* root,int father){
        if(!root)
            return true;
        if(root->left  ){
            if( root->val <= root->left->val)
                return false;
            if( root->val > father && root->left->val <= father )
                return false;
        }
        if(root->right){
            if( root->val >=  root->right->val)
                return false;
            if( root->val < father && root->right->val >= father )
                return false;
        }
            
                
        return recur_isValidBST(root->left,root->val) && recur_isValidBST(root->right,root->val);
    }

    
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root->left  && root->val <= root->left->val)
    
            return false;
        if(root->right && root->val >=  root->right->val)
            
            return false;
        return recur_isValidBST(root->left,root->val) && recur_isValidBST(root->right,root->val);
    }
};

/* 最值得注意的是 搜索二叉树的中序遍历是单调数列。 反之亦成立 */
# if 0
class Solution {
private:
    std::vector<int> vec;

void inoder_traversal(TreeNode* node){
    if(!node) return;
    inoder_traversal(node->left);
    vec.push_back(node->val);
    inoder_traversal(node->right);
    return;
}

    
public:
    bool isValidBST(TreeNode* root) {
        vec.clear();
        inoder_traversal(root);
        for(int i=0;i<vec.size();i++){
            if(vec[i] <= vec[i-1])
                return false;
        }

        return true;
    }
};
#endif

class Solution {
private:
    
public:
    bool isValidBST(TreeNode* root) {
        

        return true;
    }
};
int main() {

    return 0;
}