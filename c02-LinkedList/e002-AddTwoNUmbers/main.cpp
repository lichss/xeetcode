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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tail = new ListNode(0);
        tail->next = nullptr;
        ListNode* head = nullptr;
        ListNode* prev = tail;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;
            if(l1 != nullptr)
                sum += l1->val;
            if(l2 != nullptr)
                sum += l2->val;
            carry = sum / 10;
            head = new ListNode(sum % 10);
            head->next = prev;    
        }

        return head;
    }
};

// class Solution2 {
// public:
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     ListNode* tail = new ListNode(0);
//     tail->next = nullptr;
//     ListNode* head = nullptr;
//     ListNode* prev = tail;
//     int carry = 0;
//     while(l1 != nullptr || l2 != nullptr || carry != 0){
//         int sum = carry + (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0);
//         carry = sum / 10;
//         head = new ListNode(sum % 10);
//         head->next = prev;
//         prev = head;
//         if(l1 != nullptr) l1 = l1->next;
//         if(l2 != nullptr) l2 = l2->next;
//     }
//     return head;
// }
// };

int main(){


    return 0;
}
