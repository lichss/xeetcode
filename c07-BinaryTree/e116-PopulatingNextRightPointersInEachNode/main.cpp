#include <vector>
#include <iostream>
#include <queue>

#include "../leetcodeStruct/node"
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> qu;
        std::vector<Node*> layer;
        Node* node;
        int nextLevel = 0, currentLevel = 1;

        qu.push(root);
        while(!qu.empty()){
            node = qu.front();
            qu.pop();
            layer.push_back(node);

            if(node->left){
                qu.push(node->left);
                nextLevel ++;
            }
            if(node->right){
                qu.push(node->right);
                nextLevel ++;
            }
            if(--currentLevel == 0){
                currentLevel = nextLevel;
                nextLevel = 0;
                for(int i=0;i<layer.size()-1;i++)
                    layer[i]->next = layer[i+1];
                
                layer.clear();
            }
        }
        return root;
    }
};

int main() {
    return 0;
}