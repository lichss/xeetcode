#include <iostream>



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next){
            slow = slow->next;

            if(fast->next->next)
                fast = fast->next->next;
            else
                return slow;
                       
        }
        return slow;        
    }
};

#if 1

int main(){



    return 0;
}

#endif