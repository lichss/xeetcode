#include <vector>
// #include <iostream>
#include <queue>
#include <deque>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        if((root->left == nullptr) != (root->right == nullptr)) return false;
        auto isSyme = [](TreeNode* nodel, TreeNode* noder){
            if(nodel->val == noder->val) 
                if((nodel->left == nullptr) == (noder->right == nullptr))
                    if((nodel->right == nullptr) == (noder->left == nullptr)) 
                        return true;
            
            return  false;
        };
        std::vector<TreeNode*> vec;
        std::queue<TreeNode*> qu;qu.push(root);
        int curLevel_n=1, nextLevel_n=0;
        TreeNode* node;

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
            vec.push_back(node);
            if(!curLevel_n){
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
                for(int i=0,n=vec.size()-1; i<vec.size()/2; i++)
                   if(! isSyme(vec[i],vec[n-i]) ) return false;
    
                vec.clear();
           }
            
        }
        return true;
    }
};

int main() {
    return 0;
}