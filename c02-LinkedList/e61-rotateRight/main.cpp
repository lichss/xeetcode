#include <iostream>



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*嘻嘻 我要用线性表*/
#include <vector>
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;            
        std::vector<ListNode*> v;
        for(auto node = head;node;node = node->next){
            v.push_back(node);            
        }
        int n = v.size()-1;
        k = k%v.size();
        if(!k)
            return head;

        v.back()->next = v[0];
        ListNode* newhead = v[n-k+1];
        ListNode* newend = v[n-k];
        newend->next = nullptr;
        
        return newhead;
    }
};


int main(){



    return 0;
}