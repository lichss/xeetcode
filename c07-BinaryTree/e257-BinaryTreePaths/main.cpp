#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include <string>

class Solution {

void recurf(TreeNode* node,std::string rec,std::vector<std::string>& vec){
    if(!node) return;

    rec += std::to_string(node->val);

    if(!node->left && !node->right)
        vec.push_back(rec);
    else
        rec += "->";

    recurf(node->left,rec,vec);
    recurf(node->right,rec,vec);

    return;  
}   

public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        std::vector<std::string> vec;
        std::string rec;

        recurf(root,rec,vec);
    
        return vec;
    }
};
int main() {
    return 0;
}