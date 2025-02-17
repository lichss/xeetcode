#include <vector>
// #include <iostream>
#include <queue>
// #include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include "../leetcodeStruct/treenode"

/* 不算难，不过需要考虑的条件多一点。 */
/* 另外 描述里说题目的进阶是使用O(N)复杂度，这个是O(N)复杂度

我没想过不用ON怎么做
*/
class Solution {
private:
    TreeNode* prevNode = nullptr;
    bool isLeftLinked = false;
public:
TreeNode* step2_DeleteAndReplace(TreeNode* root){
        
    if(!root)
        return nullptr;
    
    if((root->right == nullptr) ^ (root->left == nullptr)  ){
        /* 有一个子树为空 */
        return root->left ? root->left : root->right;
    }
    if(!root->left && !root->right) /*两个子树为空*/
        return nullptr;
    else{       
        TreeNode* node = root->right;
        while(node->left)
            node = node->left;         
        
        node->left = root->left;
        return root->right;
    }

}

TreeNode* step1_find(TreeNode* root,int key){
    TreeNode* node = root;
    while(node && key != node->val){
        if(key > node->val){
            prevNode = node;
            isLeftLinked = false;
            node = node->right;

        }else{
            prevNode = node;
            isLeftLinked = true;
            node = node->left;

        }       
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root)
        return nullptr;
    TreeNode* delTargetNode =  step1_find(root,key);
    if(!delTargetNode)  /*未找到删除点*/
        return root;
    TreeNode* replaceNode = step2_DeleteAndReplace(delTargetNode);

    if(prevNode){   /*存在上衣节点*/
        if(isLeftLinked)
            prevNode->left = replaceNode;
        else
            prevNode->right = replaceNode;
        return root;
    }else{          /* 不存在上衣节点。删除当前根节点；*/
        return replaceNode;

    }
    return root;
}
};

int main() {

    return 0;
}