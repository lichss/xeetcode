#include <iostream>
#include <vector>
#include <queue>


// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
        std::vector<std::vector<int>> vec;
        std::vector<int> layer;
        std::queue<Node*> qu;
        qu.push(root);
        int nextLevel_n = 0;
        int curLevel_n = 1;
        

        Node* node;
        while (!qu.empty()){
            node = qu.front();
            qu.pop();
            for(auto child:node->children){
                qu.push(child);
                nextLevel_n++;
            }
            curLevel_n--;
            layer.push_back(node->val);

            if(!curLevel_n){
                vec.push_back(layer);
                layer.clear();
                curLevel_n = nextLevel_n;
                nextLevel_n = 0;
            }
            /* code */
        }
        return vec;
        
    }
};

int main(){
    std::cout<<"sasda\n";


    return 0;
}