#include <iostream>
#include <vector>
#include <queue>
#include "../leetcodeStruct/treenode.h"

class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {};
        std::vector<double> vec;
        std::queue<TreeNode*> qu;
        qu.push(root);
        int nextLevel_n = 0;
        int curLevel_n = 1;
        int level_n = 1;

        double sum = 0;
        double av = 0.;
        TreeNode* node = root;
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
            sum += node->val;
            curLevel_n--;
            if(!curLevel_n){
                av = sum/level_n;
                curLevel_n = nextLevel_n;
                level_n = nextLevel_n;
                nextLevel_n = 0;
                sum = 0;
                vec.push_back(av);
            }

        }
        return vec;
        
    }
};

int main(){
    std::cout<<"sasda\n";



    return 0;
}