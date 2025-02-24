#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"

class Solution {
private:
    TreeNode* pre=nullptr;
    std::vector <int> modes ;
    int highInHistory=0;
    int curCount = 0;
    void indorRecurTrav(TreeNode* node){
        if(!node) return;
        indorRecurTrav(node->left);
        if (pre){
            if(pre->val == node->val)
                curCount++;
            else{
                if( curCount == highInHistory)
                    modes.push_back(node->val);
                if(curCount > highInHistory){
                    modes.clear();
                    modes.push_back(node->val);
                    highInHistory = curCount;
                }
                curCount = 1;
            }
        }
        pre = node;
        indorRecurTrav(node->right);
        return;

    }
public:
    std::vector<int> findMode(TreeNode* root) {
        modes.clear();
        indorRecurTrav(root);
        return modes;
    }
};

int main() {

    return 0;
}