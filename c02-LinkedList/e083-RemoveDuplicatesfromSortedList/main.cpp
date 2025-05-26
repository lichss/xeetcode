#include <iostream>
#include <vector>
#include <algorithm>


//  Definition for singly-linked list.
namespace xcs{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
}
using xcs::ListNode;

/*
 * 你说是简单题对吧,那么轮到我重拳出击了
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while(node){
            if(node->next && node->val == node->next->val){
                node->next = node->next->next;
            }else{
                node = node->next;
            }
        }
        return head; 
    }
};

int main(){


    return 0;
}
