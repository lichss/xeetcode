#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"

/*
程升力抠史上的又一丰碑。
古希腊掌握弟归的神。
直接奖励自己看一会儿摩托车视频
*/
class Solution {

private:
    // int tp,tq;
    TreeNode* tp,*tq;
    TreeNode* ancestor=nullptr;

    bool recurSearchPostOrder(TreeNode* node){
        if(!node) return false;
        bool findInSelf = node == tp || node == tq;
        bool findInLeft = recurSearchPostOrder(node->left);
        bool findInRight = recurSearchPostOrder(node->right);

        if(findInSelf && (findInLeft || findInRight) && !ancestor)
            ancestor = node;
        if(findInLeft && findInRight && !ancestor)
            ancestor = node;
        
        return findInSelf || findInLeft || findInRight;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        tp = p;
        tq = q;

        recurSearchPostOrder(root);
        return ancestor;


    }
};

int main() {

    return 0;
}