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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* node = head;
        bool dup = false;
        while(node && node->next){
            dup = false;
            while(node->next && node->val == node->next->val){
                node->next = node->next->next;  /* del node.next*/
                dup = true;
            }
            if(dup){
                prev->next = node->next;    /*del node */
            }else
                prev = node;
            node = node->next;
        }
        auto newhead = dummy->next;
        delete dummy;           /* waring Leaking! */
        return newhead;
    }
};




int main(){


    return 0;
}
