#include <iostream>
#include <vector>
#include <stack>
#include "../leetcodeStruct/treenode.h"

class Solution {
int recur(TreeNode* node,std::vector<int>& vec){
    if(node){
        vec.push_back( node->val);
        recur(node->left,vec);
        recur(node->right,vec);
    }

    
    return 0;
}
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<int> sta;
        return vec;
    }
};

class Solutionit {
int recur(TreeNode* node,std::vector<int>& vec){
    if(node){
        vec.push_back( node->val);
        recur(node->left,vec);
        recur(node->right,vec);
    }

    
    return 0;
}


public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<int> sta;
        return vec;
    }
};

int main(){
    TreeNode node;
    node.val = 1;
    std::cout<<"sasda\n";
    return 0;
}