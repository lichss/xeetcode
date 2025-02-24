#include <vector>
#include <queue>
#include <algorithm>
#include "../leetcodeStruct/treenode.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        std::vector<int> vec;
        std::vector<int> layer;
        if(root == nullptr) return {};

        std::queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* node;
        int nextLevel_n = 0;
        int curLevel_n = 1;
        int layerMax;

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
            layer.push_back(node->val);
            if(!curLevel_n){                
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
                layerMax = *max_element(layer.begin(), layer.end());
                vec.push_back(layerMax);
                layer.clear();
            }
        }
        return vec;     
    }
};

int main(){

    return 0;
}