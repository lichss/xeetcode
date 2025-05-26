#include <iostream>
#include <vector>
#include <algorithm>


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * 百般武艺 此乃线性表法
 */
class Solution {
private:
    void swapK(std::vector<ListNode*>& vec, int k){

        for(int i=0; i+k <= vec.size();i+=k)
            for(int j=0;j<(k+1)/2;j++)
                std::swap(vec[i+j],vec[i+k-j-1]);
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;

        std::vector<ListNode*> vec;
        ListNode* node = head;
        while(node){
            vec.push_back(node);
            node = node->next;
        }
        swapK(vec,k);
        for(int i=0;i<vec.size()-1;i++)
            vec[i]->next = vec[i+1];
        
        vec[vec.size() - 1]->next = nullptr;

        return vec[0];

    }
};

int main(){


    return 0;
}
