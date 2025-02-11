#include <iostream>
#include <vector>
#include <stack>

#include "../leetcodeStruct/treenode.h"

class Solution {
    int recur(TreeNode* node,std::vector<int>& vec){
        if(!node)
            return 0;
        recur(node->left,vec);
        vec.push_back(node->val);
        recur(node->right,vec);
        return 0;
    }
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        recur(root,vec);

        return vec;
    }
};
/*-------------------------------------------*/
class Solutionit {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<TreeNode*> sta;

        TreeNode* node = root;
        while(node || !sta.empty()){
            if(node){   /*node有效*/
                if(node->left){
                    sta.push(node);
                    node = node->left;
                }else{
                    vec.push_back(node->val);
                    node = node->right;
                }            
            }else{      /*node无效，只能是上一个节点左右都没有子节点，栈上的节点相对位置处于'中'，可以直接返回值，并且进入右子节点*/
                node = sta.top();
                sta.pop();
                vec.push_back(node->val);
                node = node->right;
            }
        }
        return vec;
    }
};

int main(){

    std::cout<<"sasda\n";
    Solution s1;
    Solutionit s2;

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);

    // 构建树结构
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node8;
    node5->left = node6;
    node5->right = node7;
    node8->left = node9;

    auto pp = [](std::vector<int>& vec){
        for(auto e:vec)
            std::cout<<e<<" ";
        std::cout<<"\n";        
    };
    

    std::vector<int> vec = s1.inorderTraversal(node1);
    std::vector<int> vvv = s2.inorderTraversal(node1);
    std::cout<<"correct:\n";
    pp(vec);
    std::cout<<"yours:\n";
    pp(vvv);

    std::cout<<"\n";
    return 0;
}