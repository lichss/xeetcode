#include <iostream>
#include <vector>
#include <stack>


#include "../leetcodeStruct/treenode.h" 

class Solution_recur {
    int recur(TreeNode* node,std::vector<int>& vec){
        if(!node)
            return 0;
        recur(node->left,vec);
        recur(node->right,vec);
        vec.push_back(node->val);

        return 0;
    }
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        recur(root,vec);

        return vec;
    }
};

/*-------------------------------------------*/
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<TreeNode*> sta;
        TreeNode* node = root;
        TreeNode* tail;

        while(node ||!sta.empty()){
            if(node){           /*当前节点有效*/
                if(node->left || node->right){/*可以向下迭代*/
                    sta.push(node);     
                    if(node->left && node->right){
                        sta.push(node->right);
                        node = node->left;
                    }
                    else if(node->left)
                        node = node->left;
                    else
                        node = node->right;
                }else{              /*不能向下迭代 处于一个末端节点 保证栈不空*/
                    vec.push_back(node->val);
                    tail = node;
                    node = nullptr;
                }
                            
            }else{          /*当前节点无效*/

                while(sta.top()->left == tail || sta.top()->right == tail){
                    vec.push_back(sta.top()->val);
                    tail = sta.top();
                    sta.pop();
                    if(sta.empty())
                       return vec;
                }
                node = sta.top();
                sta.pop();
            }
        }

        return vec;
    }
};

int main(){

    std::cout<<"sasda\n";
    Solution_recur s1;
    Solution s2;

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
    

    std::vector<int> vec = s1.postorderTraversal(node1);
    std::vector<int> vvv = s2.postorderTraversal(node1);
    std::cout<<"correct:\n";
    pp(vec);
    std::cout<<"yours:\n";
    pp(vvv);

    std::cout<<"\n";
    return 0;
}